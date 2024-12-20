#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        
        int scores[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &scores[i]);
        }
        
        int *p = &scores[n / 2];
        printf("%d %d\n", *(p - 1), *(p + 1));
        
        int index;
        scanf("%d", &index);
        
        int distance = index - 1 - n / 2;
        printf("%d\n", *(p + distance));
    }
    
    return 0;
}