#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

void position(int x, int y) 
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void trimWhitespace(char *str) 
{
    int start = 0, end = strlen(str) - 1;

    while (isspace(str[start])) 
	{
        start++;
    }

    while (end > start && isspace(str[end])) 
	{
        end--;
    }
    memmove(str, str + start, end - start + 1);
    str[end - start + 1] = '\0';
}

struct data
{
    int ID;
    char nama_siswa[101];
    char jenis_kursus[13];
    int nilai_quiz;
    int nilai_tugas;
    int nilai_ujian;
    float nilai_akhir;
};

char grading(float nilai_akhir)
{
	if (nilai_akhir >= 85)
	{
		return 'A';
	}
	else if (nilai_akhir < 85 && nilai_akhir >= 70)
	{
		return 'B';
	}
	else if (nilai_akhir < 70 && nilai_akhir >= 60)
	{
		return 'C';
	}
	else if (nilai_akhir < 60 && nilai_akhir >= 50)
	{
		return 'D';
	}
	else
	{
		return 'F';
	}
};

void pendataan() 
{
    int n, i;

    FILE *thefile = fopen("DataSiswa.txt", "a");
    FILE *fp = fopen("DataSiswaRaw.txt", "a");

    if (thefile == NULL) 
	{
        printf("File Can't Be Opened\n");
        exit(1);
    }
    
     if (fp == NULL) 
	{
        printf("File Can't Be Opened\n");
        exit(1);
    }

    position(20, 14);
    printf("|Pendataan Siswa\n");
    position(129, 14);
    printf("|");
    position(20, 15);
    printf("==============================================================================================================");
    position(129, 16);
    printf("|");
    position(20, 17);
    printf("==============================================================================================================");
    position(20, 16);
    printf("|Masukkan Jumlah Data Siswa Yang Ingin Diinput : ");
    scanf("%d", &n);

    struct data sws[n];
    for (i = 0; i < n; i++) 
	{
        // Repetition for design
        for (int v = 17; v < 34; v++) 
		{
            position(20, v);
            printf("|   |");
            position(129, v);
            printf("|");
        }

        // Repetition for design
        for (int j = 18; j < 34; j++) 
		{
            position(75, j);
            printf("|");

            position(92, j);
            printf("|");
        }

        position(20, 17);
        printf("==============================================================================================================");
        position(20, 25);
        printf("|[%d]|", i + 1);
        position(20, 34);
        printf("==============================================================================================================");
        position(25, 19);
        printf(" 1. Input ID Siswa       : ");
        scanf("%d", &sws[i].ID);
        fprintf(thefile, " 1. ID Siswa             : %d\n", sws[i].ID);
        getchar();
        position(25, 21);
        printf(" 2. Input Nama Siswa     : ");
        fgets(sws[i].nama_siswa, sizeof(sws[i].nama_siswa), stdin);
        fprintf(thefile, " 2. Nama Siswa           : %s", sws[i].nama_siswa);
        trimWhitespace(sws[i].nama_siswa);
        position(76, 18);
        printf("|| PENJELASAN ||");
        position(76, 20);
        printf(" 2.Jenis Kursus");
        position(76, 22);
        printf(" Beginner ");
        position(76, 24);
        printf(" Intermediate ");
        position(76, 26);
        printf(" Advanced ");
        position(25, 23);
        printf(" 3. Jenis Kursus         : ");
        scanf("%s", sws[i].jenis_kursus);
        fprintf(thefile, " 3. Jenis Kursus         : %s\n", sws[i].jenis_kursus);
        position(25, 25);
        printf(" 4. Masukkan Nilai Quiz  : ");
        scanf("%d", &sws[i].nilai_quiz);
        fprintf(thefile, " 4. Nilai Quiz           : %d\n", sws[i].nilai_quiz);
        position(25, 27);
        printf(" 5. Masukkan Nilai Tugas : ");
        scanf("%d", &sws[i].nilai_tugas);
        fprintf(thefile, " 5. Nilai Tugas          : %d\n", sws[i].nilai_tugas);
        position(25, 29);
        printf(" 6. Masukkan Nilai Ujian : ");
        scanf("%d", &sws[i].nilai_ujian);
        fprintf(thefile," 6. Nilai Ujian          : %d\n", sws[i].nilai_ujian);
        

        // Hitung Nilai Akhir Kursus (NA)
        sws[i].nilai_akhir = (0.3 * sws[i].nilai_quiz) + (0.3 * sws[i].nilai_tugas) + (0.4 * sws[i].nilai_ujian);
        char finalGrade = grading(sws[i].nilai_akhir);
		position(104, 18);
        printf("||Grade||");
        position(100, 20);
        printf("Grade A : 85 - 100");
        position(100, 22);
        printf("Grade B : 70 - 84");
        position(100, 24);
        printf("Grade C : 60 - 69");
        position(100, 26);
        printf("Grade D : 50 - 59");
        position(100, 28);
        printf("Grade E : 0  - 49");
        position(93, 30);
        printf("************************************");
        position(100, 32); printf("Final Grade : %.2f '%c'", sws[i].nilai_akhir, finalGrade);
        fprintf(thefile," 7. Final Grade          : %.2f '%c'\n", sws[i].nilai_akhir, finalGrade);
        position(25, 31);
        system("pause");
        position(25, 32);
		fprintf(fp, "%d;%s;%s;%d;%d;%d;%.2f;%c\n", sws[i].ID, sws[i].nama_siswa, sws[i].jenis_kursus, sws[i].nilai_quiz, sws[i].nilai_tugas, sws[i].nilai_ujian, sws[i].nilai_akhir, finalGrade);
        fprintf(thefile, "\n");    
        system("cls");
    }
    fclose(thefile);
    fclose(fp);
}



void sort()
{
    // Implement sorting logic here
}

void search() 
{
    // Implement search logic here
}

void refresh()
{
	
}

int main() 
{
    system("mode 650");
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

    int choice = 0;

    do 
    {
    menu:
        position(20, 7);
        printf("==============================================================================================================");
        position(20, 8);
        printf("| Pendataan Nilai English Course");
        position(129, 8);
        printf("|");
        position(20, 9);
        printf("==============================================================================================================");
        position(20, 10);
        printf("| 1. Pendataan");
        position(20, 11);
        printf("| 2. Sorting");
        position(20, 12);
        printf("| 3. Search Data");
        position(50, 10);
        printf("|");
        position(50, 11);
        printf("|");
        position(50, 12);
        printf("|");
        position(50, 13);
        printf("|");
        position(51, 10);
        printf("====================");
        position(51, 12);
        printf("====================");
        position(70, 11);
        printf("|");
        position(129, 12);
        printf("|");
        position(129, 10);
        printf("|");
        position(129, 11);
        printf("|");
        position(129, 13);
        printf("|");
        position(91, 11);
        printf("|KETIK 4 UNTUK REFRESH|");
        position(20, 13);
        printf("==============================================================================================================");
        position(51, 11);
        printf("Answer : ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                pendataan();
                system("cls");
                break;
            case 2:
                sort();
                system("cls");
                break;
            case 3:
                search();
                system("cls");
                break;
            case 4:
            	refresh();
            	system("cls");
            	break;
            default:
                position(78, 14); 
                printf("||Invalid choice. Please enter a valid option||\n");
                goto menu;
        }
    } while (choice != 6);
    return 0;
}

