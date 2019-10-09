/******************************************************************************
 * emigrate-rpt.c                                                             *
 *                                                                            *
 * Problem 3.5 from MIT Practical C Programming Course; read a file of data   *
 * that is tab delimited and produce a report based on specifications.        *
 *                                                                            *
 * Ben Wheeless, 10/07/2019                                                   *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StateRecord ;
typedef struct StateRecord *StateRecordPtr ;
typedef StateRecordPtr StateList ;
typedef StateRecordPtr NextState ;

struct StateRecord {
    char StateCode[5] ;
    char State[50] ;
    NextState Next ;
} ;

#define DEBUG 0

const char STATE_OF_EXIT[]  = "\"MASSACHUSETTS\"" ;

void usage(char* programName)
{
    printf("\nUsage:\n") ;
    printf("\t%s <filename>\n\n", programName) ;
    printf("Where:\n") ;
    printf("\tfilename = Name of tab delimited file to process.\n\n") ;

    exit(EXIT_FAILURE) ;
}

int main(int argc, char* argv[])
{
    char* prog = argv[0] ;
    FILE* fp=NULL ;
    char columnHead[50] ;
    int hdr = 0 ;
    char OrigStateCd[5], OrigCountryCd[6], DestStateCd[5], DestCountryCd[6], 
         StateAbbr[5], StateName[50] ;
    unsigned int ReturnNum, NumExmpt, AggrAGI ;
    unsigned int recordsRead = 0, stateRecords = 0, len = 0 ;

    /* Check program arguments and open specified input file */
    if( argc != 2) 
    {
        printf( "ERROR - invalid number of arguments.\n" ) ;
        usage(prog) ;
    } 
    else
    {
        fp = fopen(argv[1], "r") ;
    }

    /* File expected to have header, so treat first record special */
    hdr = fscanf(fp, "%s%s%s%s%s%s%s%s%s", columnHead, columnHead, columnHead, 
        columnHead, columnHead, columnHead, columnHead, columnHead, columnHead) ;

    if( hdr == 0 || hdr == EOF )
    {
        printf("An error occurred reading header record from input file.\n") ;
        exit(EXIT_FAILURE) ;
    }

    /* Now read the rest of the file */
    while( fscanf(fp, "%s%s%s%s%s%s%d%d%d", OrigStateCd, OrigCountryCd, DestStateCd, DestCountryCd, 
        StateAbbr, StateName, &ReturnNum, &NumExmpt, &AggrAGI) != EOF )
    {
        recordsRead++ ;
        if( DEBUG ) 
            printf( "%06d: Record read for state = %s\n", recordsRead, StateName ) ;

        len = strlen(StateName) ;
        if(strncmp(STATE_OF_EXIT, StateName, len) == 0)
        {
            printf("State Code = %s, State = %s\n", DestStateCd, StateAbbr) ;
            stateRecords++ ;
        }
    }

    fclose(fp) ;

    printf("Total Records found for exit state = %s := %d\n", STATE_OF_EXIT, stateRecords) ;

    return(0) ;
}
