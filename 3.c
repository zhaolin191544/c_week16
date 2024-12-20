#include <stdio.h>
#include <string.h>

char* substr(char *s, int startloc, int len) {
   static char result[50];  
   int slen = strlen(s);    
   if (startloc > slen) {
       return NULL;
   }
   startloc--;
   int actual_len = slen - startloc;
   if (actual_len > len) {
       actual_len = len;
   }
   int i;
   for (i = 0; i < actual_len; i++) {
       result[i] = s[startloc + i];
   }
   result[i] = '\0';
   return result;
}

int main() {
   int t;
   char s[50];
   int startloc, len;
   scanf("%d", &t);  
   while (t--) {
       scanf("%s", s);
       scanf("%d %d", &startloc, &len);
       
       char *result = substr(s, startloc, len);
       if (result == NULL) {
           printf("NULL\n");
       } else {
           printf("%s\n", result);
       }
   }
   
   return 0;
}