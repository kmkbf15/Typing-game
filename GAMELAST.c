#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>

struct score{
	char nama[101];
	char akur[101];
	char wpm[101];
	char jml_kata[101];
	char time[101];
};

struct urut{
	char nama[101];
	char akur[101];
	int wpm;
	char jml_kata[101];
	char time[101];
};

struct player{ //masukkin ke data highscore
	char nama[101];
	float akur;
	int wpm;
	int jml_kata;
	double time;
};
struct list{
	char kata[30];
};

struct list kamus[500];
struct score highscore[101];
struct player user;
struct urut sort[101];
struct urut temp;
char kata_1[500][30];

void gameplay(){ //typing game
	system("cls");
	clock_t t;
	double waktu;
	char jawaban[30];
	
	//5s countdown
	int cntdown = 5;
	while(cntdown !=0){
		printf("\n\t%d", cntdown);
		cntdown--;
		sleep(1);
		system("cls");
	}
	
	t = clock();//mulai
	float skor=0;
	int i;
	for(i=0;i<user.jml_kata;i++){
		printf("%s ", kata_1[i]);
	}
	printf("\n");
	for(i=0;i<user.jml_kata;i++){
		scanf("%s", jawaban);
		if(strcmp(kata_1[i], jawaban)==0){
			skor+=1;
		}
	}
	float akurasi = (skor/user.jml_kata)*100;
	t = clock() - t;
	waktu = ((double)t)/CLOCKS_PER_SEC;
	user.time = waktu;
	int wpm = 60/waktu*user.jml_kata;
	getchar();
	printf("Your result is : %d WPM and %.2f%% ACCURACY and %.2lf second\n\nPress any key to continue...\n", wpm, akurasi,waktu);
	user.akur = akurasi;
	user.wpm = wpm;
	getchar();
	
}

void persiapan_level(){
	int j;
	int x;
	srand(time(NULL));
	for(j=0;j<user.jml_kata;j++){
		x = rand()%497;
		strcpy(kata_1[j], kamus[x].kata);
	}
};

void isi_nama(){ //input nama
	system("cls");
	printf("Insert your name(max 10 character, single word): ");
	scanf("%s", user.nama);
	printf("How many words do you want?\n");
	scanf("%d", &user.jml_kata);
	getchar();
	printf("Press any key to start\n");
	getch();
}
void input_highscore(){
	FILE *fp = fopen("highscore.txt", "a");
	fprintf (fp,"%s;%d;%d;%.2f;%.2lf\n",user.nama,user.jml_kata,user.wpm,user.akur,user.time);
	fclose(fp);
	
}
void show_highscore(){
	char buffer[101];
	int i=0;
	FILE *fp = fopen("highscore.txt", "r");
	while(fgets(buffer, sizeof(buffer), fp) != NULL){
    	sscanf(buffer,"%[^;];%[^;];%[^;];%[^;];%[^;\n]",highscore[i].nama,highscore[i].jml_kata,highscore[i].wpm,highscore[i].akur,highscore[i].time);
    	if(strlen(highscore[i].nama)<=4){
    		if(strlen(highscore[i].akur)<=5){
    			printf("%d. %s\t\t\t%s Word(s)\t%s wpm\t%s%% \tAccuracy\t%s second\n",i+1,highscore[i].nama,highscore[i].jml_kata,highscore[i].wpm,highscore[i].akur,highscore[i].time);
			}else{
				printf("%d. %s\t\t\t%s Word(s)\t%s wpm\t%s%% Accuracy\t%s second\n",i+1,highscore[i].nama,highscore[i].jml_kata,highscore[i].wpm,highscore[i].akur,highscore[i].time);
			}
    	}else{
    		if(strlen(highscore[i].akur)<=5){
    		printf("%d. %s\t\t%s Word(s)\t%s wpm\t%s%% \tAccuracy\t%s second\n",i+1,highscore[i].nama,highscore[i].jml_kata,highscore[i].wpm,highscore[i].akur,highscore[i].time);	
			}else{
				printf("%d. %s\t\t%s Word(s)\t%s wpm\t%s%% Accuracy\t%s second\n",i+1,highscore[i].nama,highscore[i].jml_kata,highscore[i].wpm,highscore[i].akur,highscore[i].time);
			}	
		}
    	
	i++;
	}
    
    fclose(fp);
    printf ("Press any key to continue\n");
    getch();
}

void cari_nama(){
	system("cls");
	char buffer[101];
	char nama[101];
	int i=0;
	printf("Masukan nama yang ingin dicari: ");
	scanf("%s",nama);
	
	FILE *fp = fopen("highscore.txt","r");
	while(fgets(buffer, sizeof(buffer), fp) != NULL){
    sscanf(buffer,"%[^;];%[^;];%[^;];%[^;];%[^;\n]",highscore[i].nama,highscore[i].jml_kata,highscore[i].wpm,highscore[i].akur,highscore[i].time);
    if(strcmp(nama,highscore[i].nama)==0){
    	if(strlen(highscore[i].nama)<=4){
    		if(strlen(highscore[i].akur)<=5){
    			printf("%d. %s\t\t\t%s Word(s)\t%s wpm\t%s%% \tAccuracy\t%s second\n",i+1,highscore[i].nama,highscore[i].jml_kata,highscore[i].wpm,highscore[i].akur,highscore[i].time);
			}else{
				printf("%d. %s\t\t\t%s Word(s)\t%s wpm\t%s%% Accuracy\t%s second\n",i+1,highscore[i].nama,highscore[i].jml_kata,highscore[i].wpm,highscore[i].akur,highscore[i].time);
			}
    	}else{
    		if(strlen(highscore[i].akur)<=5){
    		printf("%d. %s\t\t%s Word(s)\t%s wpm\t%s%% \tAccuracy\t%s second\n",i+1,highscore[i].nama,highscore[i].jml_kata,highscore[i].wpm,highscore[i].akur,highscore[i].time);	
			}else{
				printf("%d. %s\t\t%s Word(s)\t%s wpm\t%s%% Accuracy\t%s second\n",i+1,highscore[i].nama,highscore[i].jml_kata,highscore[i].wpm,highscore[i].akur,highscore[i].time);
			}	
		}
	}
	
	i++;
	}
	printf ("Press any key to continue\n");
    getch();
    fclose(fp);
}

void mengurutkan(){
	char buffer[100];
	int i=0;
	int N=0;
	FILE *fp = fopen("highscore.txt", "r");
	while(fgets(buffer, sizeof(buffer), fp) != NULL){
    	sscanf(buffer, "%[^;];%[^;];%d;%[^;];%[^;\n]", sort[i].nama, sort[i].jml_kata, &sort[i].wpm, sort[i].akur, sort[i].time);
    	N++;
    	i++;
	}
	
	bool swapped;
	do{ //Sort wpm
		swapped = false;
		for(i=0;i<N-1;i++){
			if(sort[i].wpm<sort[i+1].wpm){
				swapped = true;
				temp = sort[i];
				sort[i] = sort[i+1];
				sort[i+1] = temp;
			}
		}
	}while(swapped);
	fclose(fp);
	i=0;
	FILE *fwrt = fopen("highscore.txt", "w+");
	while(i<N){
		fprintf (fwrt,"%s;%s;%d;%s;%s\n", sort[i].nama, sort[i].jml_kata, sort[i].wpm, sort[i].akur, sort[i].time);
		i++;
	}
	fclose(fwrt);
	
}

int main(){
	FILE *fp = fopen("word_list_rand.txt", "r");
	int i;
	char buffer[100];
	for(i=0;i<497;i++){
		fgets(buffer, 30, fp);
		sscanf(buffer, "%[^\n]s", kamus[i].kata);
	}
	fclose(fp);
	awal:
	printf(" _______ __     __ _____   _____  _   _   _____    _____            __  __  ______ \n");
	printf("|__   __|\\ \\   / /|  __ \\ |_   _|| \\ | | / ____|  / ____|    /\\    |  \\/  ||  ____|\n");
	printf("   | |    \\ \\_/ / | |__) |  | |  |  \\| || |  __  | |  __    /  \\   | \\  / || |__   \n");
	printf("   | |     \\   /  |  ___/   | |  | . ` || | |_ | | | |_ |  / /\\ \\  | |\\/| ||  __|  \n");
	printf("   | |      | |   | |      _| |_ | |\\  || |__| | | |__| | / ____ \\ | |  | || |____ \n");
	printf("   |_|      |_|   |_|     |_____||_| \\_| \\_____|  \\_____|/_/    \\_\\|_|  |_||______|\n");
	printf("\n Menu:\n");
	printf("\t1. PLAY!\n");
	printf("\t2. HIGHSCORE\n");
	printf("\t3. QUIT\n");
	printf("\t4. CREDITS\n");
	int pilihan;
	int opsi;
	scanf("%d", &pilihan);
	switch(pilihan){
		case 1 :
			isi_nama();
			persiapan_level();
			gameplay();
			input_highscore();
			system("cls");
			goto awal;
		case 2 :
			printf("\t1. SHOW HIGHSCORE\n");
			printf("\t2. SEARCH BY NAME\n");
			scanf("%d",&opsi);
			switch(opsi){
				case 1:
					mengurutkan();
					show_highscore();
					system("cls");
				goto awal;
				case 2:
					cari_nama();
					system("cls");
				goto awal;	
				
			}
			system("cls");
			goto awal;
		case 3 :
			system("cls");
			exit(0);
		case 4 :
			printf("  _____                _           _   ____\n");
			printf(" / ____|              | |         | | |  _ \\         _\n");
			printf("| |     _ __ ___  __ _| |_ ___  __| | | |_) |_   _  (_)\n");
			printf("| |    | '__/ _ \\/ _` | __/ _ \\/ _` | |  _ <| | | |\n");
			printf("| |____| | |  __/ (_| | ||  __/ (_| | | |_) | |_| |  _\n");
			printf(" \\_____|_|  \\___|\\__,_|\\__\\___|\\__,_| |____/ \\__, | (_)\n");
			printf("                                              __/ |\n");
			printf(" _____                                       |___/_    _____ _                                              ___  _  _   _  _    ___   ___ ___  ___   __ ___  _  _\n");
			printf("|_   _|                                          | |  / ____(_)                                            |__ \\| || | | || |  / _ \\ / _ \\__ \\|__ \\ / /|__ \\| || |\n");
			printf("  | |  _ __ ___  _ __ ___   __ _ _ __  _   _  ___| | | |  __ _  _____   ____ _ _ __  _ __   ___    ______     ) | || |_| || |_| | | | | | | ) |  ) / /_   ) | || |_\n");
			printf("  | | | '_ ` _ \\| '_ ` _ \\ / _` | '_ \\| | | |/ _ \\ | | | |_ | |/ _ \\ \\ / / _` | '_ \\| '_ \\ / _ \\  |______|   / /|__   _|__   _| | | | | | |/ /  / / '_ \\ / /|__   _|\n");
			printf(" _| |_| | | | | | | | | | | (_| | | | | |_| |  __/ | | |__| | | (_) \\ V / (_| | | | | | | | (_) |           / /_   | |    | | | |_| | |_| / /_ / /| (_) / /_   | |\n");
			printf("|_____|_| |_| |_|_| |_| |_|\\__,_|_| |_|\\__,_|\\___|_|  \\_____|_|\\___/ \\_/ \\__,_|_| |_|_| |_|\\___/           |____|  |_|    |_|  \\___/ \\___/____|____\\___/____|  |_|\n");
			printf("      _       _ _            __      __   _            _   _                        ___  _  _   _  _    ___   ___ ___  ____  _____ __ ____\n");
			printf("     | |     | (_)           \\ \\    / /  | |          | | (_)                      |__ \\| || | | || |  / _ \\ / _ \\__ \\|___ \\| ____/_ |___ \\\n");
			printf("     | |_   _| |_ _   _ ___   \\ \\  / /_ _| | ___ _ __ | |_ _ _ __   ___    ______     ) | || |_| || |_| | | | | | | ) | __) | |__  | | __) |\n");
			printf(" _   | | | | | | | | | / __|   \\ \\/ / _` | |/ _ \\ '_ \\| __| | '_ \\ / _ \\  |______|   / /|__   _|__   _| | | | | | |/ / |__ <|___ \\ | ||__ <\n");
			printf("| |__| | |_| | | | |_| \\__ \\    \\  / (_| | |  __/ | | | |_| | | | | (_) |           / /_   | |    | | | |_| | |_| / /_ ___) |___) || |___) |\n");
			printf(" \\____/ \\__,_|_|_|\\__,_|___/     \\/ \\__,_|_|\\___|_| |_|\\__|_|_| |_|\\___/           |____|  |_|    |_|  \\___/ \\___/____|____/|____/ |_|____/\n");
			printf("  _____       _          _      _    __ _             _                                  ___  _  _   _  _    ___   ___ ___  ____ ____    __ ___\n");
			printf(" / ____|     | |        (_)    | |  / _| |           (_)                                |__ \\| || | | || |  / _ \\ / _ \\__ \\|___ \\___ \\  / /|__ \\\n");
			printf("| |  __  __ _| |__  _ __ _  ___| | | |_| | __ ___   ___  __ _ _ __  _   _ ___   ______     ) | || |_| || |_| | | | | | | ) | __) |__) |/ /_   ) |\n");
			printf("| | |_ |/ _` | '_ \\| '__| |/ _ \\ | |  _| |/ _` \\ \\ / / |/ _` | '_ \\| | | / __| |______|   / /|__   _|__   _| | | | | | |/ / |__ <|__ <| '_ \\ / /\n");
			printf("| |__| | (_| | |_) | |  | |  __/ | | | | | (_| |\\ V /| | (_| | | | | |_| \\__ \\           / /_   | |    | | | |_| | |_| / /_ ___) |__) | (_) / /_\n");
			printf(" \\_____|\\__,_|_.__/|_|  |_|\\___|_| |_| |_|\\__,_| \\_/ |_|\\__,_|_| |_|\\__,_|___/          |____|  |_|    |_|  \\___/ \\___/____|____/____/ \\___/____|\n");
			printf(" __  __                          _ _    _____ _ _ _               _      _____                                                  ___  _  _   _  _    ___   ___ ___   ___  _  _ ______ _  _\n");
			printf("|  \\/  |                        | | |  / ____(_) | |             | |    / ____|                                                |__ \\| || | | || |  / _ \\ / _ \\__ \\ / _ \\| || |____  | || |\n");
			printf("| \\  / | __ ___  ____      _____| | | | |  __ _| | |__   ___ _ __| |_  | |  __ _   _ _ __   __ ___      ____ _ _ __    ______     ) | || |_| || |_| | | | | | | ) | | | | || |_  / /| || |_ \n");
			printf("| |\\/| |/ _` \\ \\/ /\\ \\ /\\ / / _ \\ | | | | |_ | | | '_ \\ / _ \\ '__| __| | | |_ | | | | '_ \\ / _` \\ \\ /\\ / / _` | '_ \\  |______|   / /|__   _|__   _| | | | | | |/ /| | | |__   _|/ / |__   _|\n");
			printf("| |  | | (_| |>  <  \\ V  V /  __/ | | | |__| | | | |_) |  __/ |  | |_  | |__| | |_| | | | | (_| |\\ V  V / (_| | | | |           / /_   | |    | | | |_| | |_| / /_| |_| |  | | / /     | |  \n");
			printf("|_|  |_|\\__,_/_/\\_\\  \\_/\\_/ \\___|_|_|  \\_____|_|_|_.__/ \\___|_|   \\__|  \\_____|\\__,_|_| |_|\\__,_| \\_/\\_/ \\__,_|_| |_|          |____|  |_|    |_|  \\___/ \\___/____|\\___/   |_|/_/      |_|\n");
			printf("			                                                                                                                                                                                \n");
		printf ("Press any key to continue\n");
    	getch();
    	system("cls");
    	goto awal;
		default:
			system("cls");
			goto awal;
	}
	return 0;
}
