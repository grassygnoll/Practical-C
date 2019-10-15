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

/* Set to 1 if DEBUG prints are desired */
#define DEBUG 0

/* Change this value to search for a different state */
const char STATE_OF_EXIT[]  = "\"MASSACHUSETTS\"" ;

/******************************************************************************
 * usage() - Simply displays program usage an exits                           *
 *****************************************************************************/
void usage(char* programName)
{
    printf("\nUsage:\n") ;
    printf("\t%s <filename>\n\n", programName) ;
    printf("Where:\n") ;
    printf("\tfilename = Name of tab delimited file to process.\n\n") ;

    exit(EXIT_FAILURE) ;
}

/******************************************************************************
 * ReadHeader() - accepts FILE ptr to open file, reads first record (header)  *
 *              - returns nothing (used to "chomp" header off file basically) *
 *****************************************************************************/
void ReadHeader(FILE* F)
{
    char columnHead[50] ;
    int hdr = 0 ;

    /* File expected to have header, so treat first record special */
    hdr = fscanf(F, "%s%s%s%s%s%s%s%s%s", columnHead, columnHead, columnHead, 
        columnHead, columnHead, columnHead, columnHead, columnHead, columnHead) ;

    if( hdr == 0 || hdr == EOF )
    {
        printf("An error occurred reading header record from input file.\n") ;
        exit(EXIT_FAILURE) ;
    }
}

/******************************************************************************
 * GetStateCode() - accepts string (char *) to store state code value as      *
 *                  obtained from the input file based on STATE_OF_EXIT value *
 *                - requires open FILE ptr (file handle) to read from         *
 *****************************************************************************/
void GetStateCode(char *StateOfInterest, FILE* F)
{
    char OrigStateCd[5], OrigCountryCd[6], DestStateCd[5], DestCountryCd[6], 
         StateAbbr[5], StateName[50] ;
    unsigned int ReturnNum, NumExmpt, AggrAGI ;
    unsigned int recs = 0 ;

    while( fscanf(F, "%s%s%s%s%s%s%d%d%d", OrigStateCd, OrigCountryCd, DestStateCd, DestCountryCd,
        StateAbbr, StateName, &ReturnNum, &NumExmpt, &AggrAGI) != EOF )
    {
        recs++ ;
        if(strncmp(STATE_OF_EXIT, StateName, strlen(StateName)) == 0)
        { 
            strncpy(StateOfInterest, DestStateCd, strlen(DestStateCd)) ;
            if(DEBUG)
                printf("Total Records Read until State of Interest Found = %04d\n", recs) ;

            break ;
        }
    }
}

/******************************************************************************
 * Main code execution/entry point of program                                 *
 *****************************************************************************/
int main(int argc, char* argv[])
{
    char* prog = argv[0] ;
    FILE* fp=NULL ;
    char OrigStateCd[5], OrigCountryCd[6], DestStateCd[5], DestCountryCd[6], 
         StateAbbr[5], StateName[50] ;
    unsigned int ReturnNum, NumExmpt, AggrAGI ;
    long GrandTotal = 0 ;
    char StateCodeOfInterest[5] ;
    unsigned int recordsRead = 0, stateRecords = 0 ;

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

    /* File assumed to have header, so read past it */
    ReadHeader(fp) ;

    /* First, find state of interest and retrieve its DestStateCd value */
    GetStateCode(StateCodeOfInterest, fp) ;

    /* Now rewind file location to beginning, consume header record, and process rest of file */
    rewind(fp) ;
    ReadHeader(fp) ;

    /* Print output header, left justify text */
    printf("%-30s\t\t%-10s\n", "STATE", "TOTAL") ;
    printf("-------------------------------------------------------\n") ;

    /* Now read the rest of the file */
    recordsRead = 0 ;
    while( fscanf(fp, "%s%s%s%s%s%s%d%d%d", OrigStateCd, OrigCountryCd, DestStateCd, DestCountryCd, 
        StateAbbr, StateName, &ReturnNum, &NumExmpt, &AggrAGI) != EOF )
    {
        recordsRead++ ;
        if( DEBUG ) 
            printf( "%06d: Record read for state = %s\n", recordsRead, StateName ) ;

        if(strncmp(OrigStateCd, StateCodeOfInterest, strlen(StateCodeOfInterest)) == 0)
        {
            if( DEBUG ) 
                printf("Orig State Code = %s, Dest State Code = %s, State Abbr = %s, State Name = %s, AggrAGI = %d\n", 
                    OrigStateCd, DestStateCd, StateAbbr, StateName, AggrAGI) ;

            /* Output results, left justify text */
            printf("%-30s\t\t%7d\n", StateName, AggrAGI) ;

            GrandTotal = GrandTotal + AggrAGI ;
            stateRecords++ ;
        }
    }

    fclose(fp) ;

    /* Print total line, left justify text */
    printf("-------------------------------------------------------\n") ;
    printf("%-30s\t\t%-10ld\n", "Total", GrandTotal) ;

    if(DEBUG)
        printf("Total Records found for exit state = %s := %d\n", STATE_OF_EXIT, stateRecords) ;

    return(0) ;
}
