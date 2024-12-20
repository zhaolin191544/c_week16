#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);  
    
    while (t--) {
        int matrix[2][3];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
        
        int rotated[3][2];
        
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                rotated[2-j][i] = matrix[i][j];  
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                printf("%d ", rotated[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
