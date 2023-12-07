/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ibm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:55:38 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/05 16:27:36 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>                                               
#include <stdlib.h>                                              
#include <locale.h>
                                              
int	main(void)                                                   
{                                                                
    char ch = 'h';
	char *string = "computer";                         
    int count = 234i;
	int hex = 0x10;
	int oct = 010;
	int dec = 10;            
    double fp = 251.7366;                                        
    //wchar_t wc = 0x0058;     /* UNICODE X */
    wchar_t wc = (wchar_t)0x0058;                                
    wchar_t ws[4];                                                       
                                                     
    printf("1234567890123%n4567890123456789\n\n", &count);          
    printf("Value of count should be 13; count = %d\n\n", count);   
    printf("%10c%5c\n", ch, ch);                                    
    printf("%25s\n%25.4s\n\n", string, string);                     
    printf("%f    %.2f    %e    %E\n\n", fp, fp, fp, fp);           
    printf("%i    %i     %i\n\n", hex, oct, dec);                   
                                                                   
/*****************  Output should be similar to:  ***************** 
                                                                    
234   +234    000234     EA    ea     352                           
                                                                    
12345678901234567890123456789                                       
                                                                    
Value of count should be 13; count = 13                             
 
                                                                      
  h    h                                                              
          computer                                                    
              comp                                                    
                                                                      
251.7366 00    251.74    2.517366e+02    2.517366E+02                  
                                                                      
16    8     10                                                        
 
*******************************************************************/  

     /* This program is compiled with LOCALETYPE(*LOCALEUCS2) and             */
     /* SYSIFCOPT(*IFSIO)                                               */
     /* We will assume the locale setting is the same as the CCSID of the */
     /* job.  We will also assume any files involved have a CCSID of      */
     /* 65535 (no convert).  This way if printf goes to the screen or     */
     /* a file the output will be the same.                               */
        setlocale(LC_ALL,
         "/QSYS.LIB/EN_US.LOCALE"); /* a CCSID 37 locale */
        ws[0] = 0x0041;        /* UNICODE A   */
        ws[1] = (wchar_t)0x0042;        /* UNICODE B   */
        ws[2] = (wchar_t)0x0043;        /* UNICODE C   */
        ws[3] = (wchar_t)0x0000;
        /* The output displayed is CCSID 37  */
        printf("1.- %lc   %ls\n\n",wc,ws);
        printf("2.- %lc   %.2ls\n\n",wc,ws);

        /* Now let's try a mixed-byte CCSID example  */
        /* You would need a device that can handle mixed bytes to  */
        /* display this correctly.                         */

        setlocale(LC_ALL,
        "/QSYS.LIB/JA_JP.LOCALE");/* a CCSID 5026 locale */

        /* big A means an A that takes up 2 bytes on the screen   */
        /* It will look bigger then single byte A                 */
        ws[0] = (wchar_t)0xFF21;        /* UNICODE big A   */
        ws[1] = (wchar_t)0xFF22;        /* UNICODE big B   */
        ws[2] = (wchar_t)0xFF23;        /* UNICODE big C   */
        ws[3] = (wchar_t)0x0000;
        wc = 0xff11;                    /* UNICODE big 1   */

        printf("3.- %lc   %ls\n\n",wc,ws);

        /* The output of this printf is not shown below and it   */
        /* will differ depending on the device you display it on,*/
        /* but if you looked at the string in hex it would look  */
        /* like this:  0E42F10F404040400E42C142C242C30F          */
        /* 0E is shift out, 0F is shift in, and 42F1 is the      */
        /* big 1 in CCSID   5026  */

        printf("4.- %lc   %.4ls\n\n",wc,ws);

        /* The output of this printf is not shown below either. */
        /* The hex would look like:                             */
        /* 0E42F10F404040400E42C10F                             */
        /* Since the precision is in bytes we only get 4 bytes  */
        /* of the string.         */

        printf("5.- %lc   %.2ls\n\n",wc,ws);

        /* The output of this printf is not shown below either. */
        /* The hex would look like:                             */
        /* 0E42F10F404040400E42C142C20F                         */
        /* The # means precision is in characters reguardless   */
        /* of size.  So we get 2 characters of the string.      */
 /*****************  Output should be similar to:  *****************


 X     ABC

 X     AB

 *******************************************************************/
 /* This program is compile LOCALETYPE(*LOCALE)  and               */
 /* SYSIFCOPT(*IFSIO)    */
     wc = (wchar_t)0x00C4;     /*  D */
     ws[0] = (wchar_t)0x00C1;        /* A   */
     ws[1] = (wchar_t)0x00C2;        /* B   */
     ws[2] = (wchar_t)0x00C3;        /* C   */
     ws[3] = (wchar_t)0x0000;
     /* The output displayed is CCSID 37  */
     printf("6.- %lc   %ls\n\n",wc,ws);

     /* Now let's try a mixed-byte CCSID example  */
     /* You would need a device that can handle mixed bytes to  */
     /* display this correctly.                         */

     setlocale(LC_ALL,
     "/QSYS.LIB/JA_JP.LOCALE"); /* a CCSID 5026 locale */

     /* big A means an A that takes up 2 bytes on the screen   */
     /* It will look bigger than single byte A                 */

     ws[0] = (wchar_t)0x42C1;        /* big A   */
     ws[1] = (wchar_t)0x42C2;        /* big B   */
     ws[2] = (wchar_t)0x42C3;        /* big C   */
     ws[3] = (wchar_t)0x0000;
     wc = 0x42F1;                    /* big 1   */

     printf("7.-%lc   %ls\n\n",wc,ws);

     /* The output of this printf is not shown below and it   */
     /* will differ depending on the device you display it on,*/
     /* but if you looked at the string in hex it would look  */
     /* like this:  0E42F10F404040400E42C142C242C30F          */
     /* 0E is shift out, 0F is shift in, and 42F1 is the      */
     /* big 1 in CCSID   5026  */

     printf("8.- %lc   %.4ls\n\n",wc,ws);

     /* The output of this printf is not shown below either. */
     /* The hex would look like:                             */
     /* 0E42F10F404040400E42C10F                             */
     /* Since the precision is in bytes we only get 4 bytes  */
     /* of the string.         */

     printf("9.-%lc   %.2ls\n\n",wc,ws);

     /* The output of this printf is not shown below either. */
     /* The hex would look like:                             */
     /* 0E42F10F404040400E42C142C20F                         */
     /* The # means precision is in characters regardless   */
     /* of size.  So we get 2 characters of the string.      */
 }
 /*****************  Output should be similar to:  *****************


 D     ABC


 *******************************************************************/
 
