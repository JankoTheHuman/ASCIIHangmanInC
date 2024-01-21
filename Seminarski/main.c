/* Janko Veselinovic NRT 56-22 */
/* Igra Vesala*/

/*********** VAZNA NAPOMENA: DA BI GRAFIKA IGRE RADILA ISPRAVNO MAXIMIZOVATI CMD PROZOR *********/
// FIGlet biblioteka se koristi za ispis reci za pogadjanje

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include <math.h>

struct recS{
	char rec[21];
	int duzinaReci;
	char pomoc[201];
};


// Funkcije:
void osnovniUpis();
void logo();
void ispisMenija();
void pobedaGrafika();
void porazGrafika();
int meni();
int brojReciUFajluu(char *imeFajla);
void IGRA();
struct recS * dodavanjeReci();
void unesiNovuRecGrafika();
void unesiPomocGrafika();
void upisReciUFajl(struct recS *recV);
int stringHasDigits(char *rec);
void hvalaNaIgranjuGrafika();
void multiplejerGrafika();
void visuljak0();
void visuljak1();
void visuljak2();
void visuljak3();
void visuljak4();
void visuljak5();
void visuljak6();
void visuljak7();
struct recS izborReci();

int izbor=0;


int main(int argc, char *argv[]){
	
	FILE* fptr;
	int i=0,j=0, igra=1, brojReciUOsnovnomFajlu=0, brojReciUDodatnomFajlu=0, resenje;
	struct recS *recV;


	

	//otvara maksimizovani CMD
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	// Kreiranje Fajla i upis predefinisanih reci za pogadjanje
	osnovniUpis();
	logo();
	brojReciUOsnovnomFajlu = brojReciUFajluu("IgraVesalaOsnovniFajl.txt");
	brojReciUDodatnomFajlu = brojReciUFajluu("IgraVesalaDodatniFajl.txt");

	Sleep(2000);

	
	while(igra){
		// ispis menija i upit za meni opciju
		ispisMenija();
		izbor=meni();

		if(izbor==1){
			IGRA();
			
			

		}else if(izbor==2){
			multiplejerGrafika();
			IGRA();

		}else if(izbor==3){
			upisReciUFajl(dodavanjeReci());


		}else if(izbor==4){
			igra=0;
			hvalaNaIgranjuGrafika();
	
		}
         
	}

}


//Upisuje u fajl neke predefinisane reci ukoliko igrac igra sam (bez da neko drugi zadaje reci)
void osnovniUpis(){
	FILE* fptr;
	int brojReciUFajlu;

	fptr = fopen("IgraVesalaOsnovniFajl.txt", "w");
	 if (fptr == NULL) {
        printf("Greska pri otvaranju fajla IgraVesalaOsnovniFajl.txt.\n");
        exit(1);
    }


	 
	rewind(fptr);

	fputs("LOPTA\n",fptr);fputs("5\n",fptr);fputs("Deca vole da se igraju sa njom!\n",fptr);
	fputs("KAMELEON\n",fptr);fputs("8\n",fptr);fputs("Zivotinja koja menja boje!\n",fptr);
	fputs("KOMPJUTER\n",fptr);fputs("9\n",fptr);fputs("Sta trenutno koristis?\n",fptr);
	fputs("SUNCOKRET\n",fptr);fputs("9\n",fptr);fputs("Raste i okrece se ka suncu!\n",fptr);
	fputs("BIBLIOTEKA\n",fptr);fputs("10\n",fptr);fputs("Mesto gde se nalazi puno knjiga!\n",fptr);
	fputs("PLANINA\n",fptr);fputs("7\n",fptr);fputs("Najvislja na svetu je Everest!\n",fptr);
	fputs("REKA\n",fptr);fputs("4\n",fptr);fputs("Nije jezero nego?\n",fptr);
	fputs("OLOVKA\n",fptr);fputs("6\n",fptr);fputs("Hemijska, tehnicka, grafitna...\n",fptr);
	fputs("SLON\n",fptr);fputs("4\n",fptr);fputs("Koja se zivotinja plasi misa?\n",fptr);
	fputs("NOVCANIK\n",fptr);fputs("8\n",fptr);fputs("Gde se novac i kartice drze?\n",fptr);


	fclose(fptr);


}


//ispisuje meni i proverava unos za opcije
int meni(){

	int izbor;

	do{
		scanf("%d",&izbor);
		fflush(stdin);
		if(izbor<1 || izbor>5) ispisMenija();
	}while(izbor<1 || izbor>5);
	
	return izbor;
}

void IGRA(){
	struct recS odabranaRec;
	struct recS *odabranaRecMultiplejer;

	char command[301] = "figlet ", *nizRec,unosSlova =' ', probanaSlova[30];
	int putaPogreseno = 0,pobeda=0, j=0;
	int i,pogodjenoSlovo=0, vecProbano=0;

	

	if(izbor==1){
		odabranaRec = izborReci();

	}else if(izbor==2){

		odabranaRecMultiplejer = dodavanjeReci();
		strcpy(odabranaRec.rec,odabranaRecMultiplejer->rec);
		odabranaRec.duzinaReci=odabranaRecMultiplejer->duzinaReci;
		strcpy(odabranaRec.pomoc,odabranaRecMultiplejer->pomoc);

		free(odabranaRecMultiplejer);
	}


	

	

	nizRec = (char *)malloc((odabranaRec.duzinaReci+1)*sizeof(char));

	for(i=0;i<odabranaRec.duzinaReci;i++){
		nizRec[i]='_';
	}
	
	nizRec[odabranaRec.duzinaReci]= '\0';

	

	do{
		puts("\n\n\n\n\n\n\n\n\n");

		switch(putaPogreseno){
			case 0:
				visuljak0();
				break;
			case 1:
				visuljak1();
				break;
			case 2:
				visuljak2();
				break;
			case 3:
				visuljak3();
				break;
			case 4:
				visuljak4();
				break;
			case 5:
				visuljak5();
				puts("\n");
				puts("(------za pomoc uneti '!' znak------)");
				break;
			case 6:
				visuljak6();
				puts("\n");
				puts("(------za pomoc uneti '!' znak------)");
				break;
			
		
		}


		if(unosSlova=='!'){
				printf("\nPOMOC:\n%s\n\n",odabranaRec.pomoc);
			}
		

		sprintf(command, "figlet %s --horizontal-layout full -f Slant", nizRec);
		system(command);

		puts("\n\n\n\n\n\n\n\n\n\n\n\n");

		do{
			scanf("%c", &unosSlova);
			fflush(stdin);

		}while(!isalpha(unosSlova) && unosSlova!='!');

		

		pogodjenoSlovo=0;

		if(unosSlova!='!') unosSlova=toupper(unosSlova);

		for(i=0;i<odabranaRec.duzinaReci;i++){
			if(unosSlova=='!') break;
			if(unosSlova==odabranaRec.rec[i]){
				nizRec[i]=odabranaRec.rec[i];
				pogodjenoSlovo=1;
			}
		
		}


		vecProbano=0;

		if(pogodjenoSlovo==0 && unosSlova!='!'){
			for(i=0;i<30;i++){

				if(unosSlova==probanaSlova[i]){
					vecProbano=1;
				}

			}

			if(vecProbano==0){
				putaPogreseno++;
				probanaSlova[j]=unosSlova;
				j++;
			}

		}

		

		if(strcmp(nizRec,odabranaRec.rec)==0){
			pobeda=1;
			printf("POBEDA JE %d",pobeda);

			puts("\n\n\n\n\n\n\n\n\n");

			switch(putaPogreseno){
				case 0:
					visuljak0();
					break;
				case 1:
					visuljak1();
					break;
				case 2:
					visuljak2();
					break;
				case 3:
					visuljak3();
					break;
				case 4:
					visuljak4();
					break;
				case 5:
					visuljak5();
					puts("\n");
					puts("(------za pomoc uneti '!' znak------)");
					break;
				case 6:
					visuljak6();
					puts("\n");
					puts("(------za pomoc uneti '!' znak------)");
					break;
			
		
			}
			puts("\n\n");
			sprintf(command, "figlet %s --horizontal-layout full -f Slant", nizRec);
			system(command);
			
			puts("\n\n\n\n\n\n\n\n\n\n\n\n");

			
		}

		if(putaPogreseno==7){
				puts("\n\n\n\n\n\n\n\n\n");

				visuljak7();	

				puts("\n\n");
				sprintf(command, "figlet %s --horizontal-layout full -f Slant", odabranaRec.rec);
				system(command);
				puts("\n\n\n\n\n\n\n\n\n\n\n\n");

		}

	}while(putaPogreseno!=7 && pobeda!=1);


	Sleep(3000);


	if(pobeda==1){
		pobedaGrafika();
		Sleep(3000);
	}else{
		porazGrafika();
		Sleep(3000);
	}


	free(nizRec);

}




struct recS izborReci(){

	FILE* fptr1;
	int brojReci,randRec, i;
	char red[201];
	struct recS odabranaRec;

	srand(time(NULL));


	brojReci = brojReciUFajluu("IgraVesalaDodatniFajl.txt") + brojReciUFajluu("IgraVesalaOsnovniFajl.txt");
	randRec = (rand() % brojReci) + 1;

	

	if(randRec<=brojReciUFajluu("IgraVesalaOsnovniFajl.txt")){

		fptr1 = fopen("IgraVesalaOsnovniFajl.txt", "r");
		if (fptr1 == NULL) {
			printf("Greska pri otvaranju fajla IgraVesalaOsnovniFajl.txt \n");
			exit(1);
		}


		for(i=0;i<(randRec*3);i++){
			fgets(red,201,fptr1);

			if((i/3)==(randRec-1)){

				red[strcspn(red, "\n")] = '\0';
				strcpy(odabranaRec.rec,red);
				fgets(red,201,fptr1);
				odabranaRec.duzinaReci= strlen(odabranaRec.rec);
				fgets(red,201,fptr1);
				strcpy(odabranaRec.pomoc,red);

				fclose(fptr1);
				break;
			
			}
		
		
		}
	
	}else{
	
		fptr1 = fopen("IgraVesalaDodatniFajl.txt", "r");
		if (fptr1 == NULL) {
			printf("Greska pri otvaranju fajla IgraVesalaDodatniFajl.txt \n");
			exit(1);
		}
		
		randRec = randRec - brojReciUFajluu("IgraVesalaOsnovniFajl.txt");

		for(i=0;i<(randRec*3);i++){
			fgets(red,201,fptr1);


			if(floor((float)(i)/3)==(randRec-1)){

				red[strcspn(red, "\n")] = '\0';
				strcpy(odabranaRec.rec,red);
				fgets(red,201,fptr1);
				odabranaRec.duzinaReci= strlen(odabranaRec.rec);
				fgets(red,201,fptr1);
				strcpy(odabranaRec.pomoc,red);

				fclose(fptr1);
				break;
			
			}
		
		
		}
	
	}


	return odabranaRec;
}


void toUpper(struct recS * rec){

	int i=0;
    
    while (rec->rec[i]) {
       rec->rec[i] = toupper(rec->rec[i]);
       i++;
    }	
}

int stringHasDigits(char *word){

	while (*word) {
        if (isdigit(*word)) {
            return 1; 
        }
        word++;
    }
    return 0; 

}


//otvara fajl i proverava koliko reci ima u faju, vraca broj reci
int brojReciUFajluu(char *imeFajla){

	FILE* fptr1;
	int brojReciUFajlu=0;
	char eof[202];

	fptr1 = fopen(imeFajla, "r");
	 if (fptr1 == NULL) {
        printf("Greska pri otvaranju fajla %s \n",imeFajla);
        exit(1);
    }

	 while(1){

		fgets(eof,202,fptr1);

		if(feof(fptr1)){
			break;
		}else{
			brojReciUFajlu++;
		}
	 }

	 fclose(fptr1);

	 return (brojReciUFajlu+1)/3;
}


void upisReciUFajl(struct recS *recV){
		FILE* fptr;

		fptr = fopen("IgraVesalaDodatniFajl.txt", "a");
		if (fptr == NULL) {
			printf("Greska pri otvaranju fajla IgraVesalaDodatniFajl.txt.\n");
			exit(1);
		}

		

		fputs(recV->rec,fptr);
		fputs("\n",fptr);

		fprintf(fptr,"%d",recV->duzinaReci);
		fputs("\n",fptr);

		if(strcmp(recV->pomoc,"")==0){
			strcpy(recV->pomoc,"Nema pomoci! >:(");
		}

		fputs(recV->pomoc,fptr);
		fputs("\n",fptr);
			
		free(recV);

		fclose(fptr);

}


//vraca pokazivac na strukturu recS
struct recS * dodavanjeReci(){

		struct recS *recV = (struct recS *)malloc(sizeof(struct recS));
		


		if (recV == NULL) {
			printf("Neuspesna alokacija memorije za strukturu rec.\n");
			exit(1); 
		}


		do{
			unesiNovuRecGrafika();
			scanf("%s",recV->rec);
			fflush(stdin);
		}while(strlen(recV->rec)<0 || strlen(recV->rec)>20 || stringHasDigits(recV->rec));


		do{
			unesiPomocGrafika();
			gets(recV->pomoc);

		}while(strlen(recV->pomoc)<0 || strlen(recV->pomoc)>200);

		
		recV->duzinaReci = strlen(recV->rec);

		toUpper(recV);

		return(recV);
}



// ------------------------------------------------------------------------------------
//      *------------------------------ GRAFIKA-----------------+------------*
//-------------------------------------------------------------------------------------


void multiplejerGrafika(){
	puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	
	puts("          __             __                           _                                         _____               __               _                                        ");
	puts("         / /  ___   ____/ /  ____ _   ____           (_)   ____ _   _____  ____ _  _____       /__  /  ____ _  ____/ /  ____ _      (_)  ___           _____  ___   _____   _ ");
	puts("    __  / /  / _ \\ / __  /  / __ `/  / __ \\         / /   / __ `/  / ___/ / __ `/ / ___/         / /  / __ `/ / __  /  / __ `/     / /  / _ \\         / ___/ / _ \\ / ___/  (_)");
	puts("   / /_/ /  /  __// /_/ /  / /_/ /  / / / /        / /   / /_/ /  / /    / /_/ / / /__          / /__/ /_/ / / /_/ /  / /_/ /     / /  /  __/        / /    /  __// /__   _   ");
	puts("   \\____/   \\___/ \\__,_/   \\__,_/  /_/ /_/        /_/    \\__, /  /_/     \\__,_/  \\___/         /____/\\__,_/  \\__,_/   \\__,_/   __/ /   \\___/        /_/     \\___/ \\___/  (_)  ");
	puts("                                                        /____/                                                                /___/                                           ");
	puts("\n");
	puts("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	puts("       ____                              _                                                __       _              ");
	puts("      / __ \\   _____  __  __   ____ _   (_)           ____   ____    ____ _  ____ _  ____/ /      (_)  ____ _   _ ");
	puts("     / / / /  / ___/ / / / /  / __ `/  / /           / __ \\ / __ \\  / __ `/ / __ `/ / __  /      / /  / __ `/  (_)");
	puts("    / /_/ /  / /    / /_/ /  / /_/ /  / /           / /_/ // /_/ / / /_/ / / /_/ / / /_/ /      / /  / /_/ /  _  ");
	puts("   /_____/  /_/     \\__,_/   \\__, /  /_/           / .___/ \\____/  \\__, /  \\__,_/  \\__,_/    __/ /   \\__,_/  (_)  ");
	puts("                            /____/                /_/             /____/                    /___/                 ");
	puts("   ");
	puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");


}

//ispisuje logo igrice
void logo(){
		puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---\n");Sleep(20);
		puts("                                                                                                                         ,--,                    ");
		puts("                                                                                                                      ,---.'|                    ");
		puts("                                                                                  ,---,.   .--.--.       ,---,        |   | :       ,---,        ");
		puts("                                                                        ,---.   ,'  .' |  /  /    '.    '  .' \\       :   : |      '  .' \\       ");
		puts("                                                                       /__./| ,---.'   | |  :  /`. /   /  ;    '.     |   ' :     /  ;    '.     ");
		puts("                                                                  ,---.;  ; | |   |   .' ;  |  |--`   :  :       \\    ;   ; '    :  :       \\    ");
		puts("                                                                 /___/ \\  | | :   :  |-, |  :  ;_     :  |   /\\   \\   '   | |__  :  |   /\\   \\   ");
		puts("                                                                 \\   ;  \\ ' | :   |  ;/|  \\  \\    `.  |  :  ' ;.   :  |   | :.'| |  :  ' ;.   :  ");
		puts("                                                                  \\   \\  \\: | |   :   .'   `----.   \\ |  |  ;/  \\   \\ '   :    ; |  |  ;/  \\   \\ ");
		puts("                                                                   ;   \\  ' . |   |  |-,   __ \\  \\  | '  :  | \\  \\ ,' |   |  ./  '  :  | \\  \\ ,' ");
		puts("                                                                    \\   \\   ' '   :  ;/|  /  /`--'  / |  |  '  '--'   ;   : ;    |  |  '  '--'   ");
		puts("                                                                     \\   `  ; |   |    \\ '--'.     /  |  :  :         |   ,/     |  :  :         ");
		puts("                                                                      :   \\ | |   :   .'   `--'---'   |  | ,'         '---'      |  | ,'         ");
		puts("                                                                       '---\"  |   | ,'                `--''                      `--''           ");
		puts("                                                                              `----'                                                             ");
		printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---");Sleep(20);printf("---\n");Sleep(20);

}



//ispis i ulazak u meni igre kao i prihvatanje dalje akcije
void ispisMenija(){
	puts("\n\n\n\n\n\n\n");
	puts("           _   .-')       ('-.        .-') _                                          _  .-')      ('-.       ");
	puts("          ( '.( OO )_   _(  OO)      ( OO ) )                                        ( \\( -O )   _(  OO)      ");
	puts("           ,--.   ,--.)(,------. ,--./ ,--,'    ,-.-')          ,-.-')    ,----.      ,------.  (,------. .-. ");
	puts("           |   `.'   |  |  .---' |   \\ |  |\\    |  |OO)         |  |OO)  '  .-./-')   |   /`. '  |  .---' `-' ");
	puts("           |         |  |  |     |    \\|  | )   |  |  \\         |  |  \\  |  |_( O- )  |  /  | |  |  |         ");
	puts("           |  |'.'|  | (|  '--.  |  .     |/    |  |(_/         |  |(_/  |  | .--, \\  |  |_.' | (|  '--.  .-. ");
	puts("           |  |   |  |  |  .--'  |  |\\    |    ,|  |_.'        ,|  |_.' (|  | '. (_/  |  .  '.'  |  .--'  `-' ");
	puts("           |  |   |  |  |  `---. |  | \\   |   (_|  |          (_|  |     |  '--'  |   |  |\\  \\   |  `---.     ");
	puts("           `--'   `--'  `------' `--'  `--'     `--'            `--'      `------'    `--' '--'  `------'     ");
	puts("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");

	puts("                    ___           ____                         __          __                    _                    ");
	puts("                   <  /          / __/ ___ _  __ _  ___   ___ / /_ ___ _  / /  ___  ___ _       (_)  ___ _  ____ ___ _");
	puts("                   / /  _       _\\ \\  / _ `/ /  ' \\/ _ \\ (_-</ __// _ `/ / /  / _ \\/ _ `/      / /  / _ `/ / __// _ `/");
	puts("                  /_/  (_)     /___/  \\_,_/ /_/_/_/\\___//___/\\__/ \\_,_/ /_/  /_//_/\\_,_/      /_/   \\_, / /_/   \\_,_/ ");
	puts("                                                                                                   /___/             ");

	puts("                     ___            ____                                        __                 _      ");
	puts("                    |_  |          /  _/  ___ _  ____ ___ _      __ __      ___/ / _  __ ___      (_) ___ ");
	puts("                   / __/  _       _/ /   / _ `/ / __// _ `/     / // /     / _  / | |/ // _ \\    / / / -_)");
	puts("                  /____/ (_)     /___/   \\_, / /_/   \\_,_/      \\_,_/      \\_,_/  |___/ \\___/ __/ /  \\__/ ");
	puts("                                        /___/                                                |___/        ");

	puts("                     ____           ___           __            _                                                    _ ");
	puts("                    |_  /          / _ \\ ___  ___/ / ___ _     (_)       ___  ___  _  __ ___        ____ ___  ____  (_)");
	puts("                   _/_ <  _       / // // _ \\/ _  / / _ `/    / /       / _ \\/ _ \\| |/ // -_)      / __// -_)/ __/ / / ");
	puts("                  /____/ (_)     /____/ \\___/\\_,_/  \\_,_/  __/ /       /_//_/\\___/|___/ \\__/      /_/   \\__/ \\__/ /_/  ");
	puts("                                                          |___/                                                       ");
                                                                      
	puts("                    ____           ____       __                  _             _                   ");
	puts("                   / / /          /  _/ ___  / / ___ _ ___       (_) ___       (_)  ___ _  ____ ___ ");
	puts("                  /_  _/ _       _/ /  /_ / / / / _ `//_ /      / / /_ /      / /  / _ `/ / __// -_)");
	puts("                   /_/  (_)     /___/  /__//_/  \\_,_/ /__/     /_/  /__/     /_/   \\_, / /_/   \\__/ ");
	puts("                                                                                  /___/             ");

	

	puts("\n\n\n\n\n\n\n\n\n\n\n\n");
}


void hvalaNaIgranjuGrafika(){
	puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
	puts("//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////");
	puts("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	puts("                                              ,--,                                                                                                                                                        ");
	puts("            ,--,                           ,---.'|                                   ,--.                                                                              ,--.        ,---._                 ");
	puts("          ,--.'|               ,---,       |   | :      ,---,                      ,--.'|   ,---,                  ,---,  ,----..   ,-.----.      ,---,              ,--.'|      .-- -.' \\                ");
	puts("       ,--,  | :       ,---.  '  .' \\      :   : |     '  .' \\                 ,--,:  : |  '  .' \\              ,`--.' | /   /   \\  \\    /  \\    '  .' \\         ,--,:  : |      |    |   :         ,--,  ");
	puts("    ,---.'|  : '      /__./| /  ;    '.    |   ' :    /  ;    '.            ,`--.'`|  ' : /  ;    '.            |   :  :|   :     : ;   :    \\  /  ;    '.    ,`--.'`|  ' :      :    ;   |       ,'_ /|  ");
	puts("    |   | : _' | ,---.;  ; |:  :       \\   ;   ; '   :  :       \\           |   :  :  | |:  :       \\           :   |  '.   |  ;. / |   | .\\ : :  :       \\   |   :  :  | |      :        |  .--. |  | :  ");
	puts("    :   : |.'  |/___/ \\  | |:  |   /\\   \\  '   | |__ :  |   /\\   \\          :   |   \\ | ::  |   /\\   \\          |   :  |.   ; /--`  .   : |: | :  |   /\\   \\  :   |   \\ | :      |    :   :,'_ /| :  . |  ");
	puts("    |   ' '  ; :\\   ;  \\ ' ||  :  ' ;.   : |   | :.'||  :  ' ;.   :         |   : '  '; ||  :  ' ;.   :         '   '  ;;   | ;  __ |   |  \\ : |  :  ' ;.   : |   : '  '; |      :         |  ' | |  . .  ");
	puts("    '   |  .'. | \\   \\  \\: ||  |  ;/  \\   \\'   :    ;|  |  ;/  \\   \\        '   ' ;.    ;|  |  ;/  \\   \\        |   |  ||   : |.' .'|   : .  / |  |  ;/  \\   \\'   ' ;.    ;      |    ;   ||  | ' |  | |  ");
	puts("    |   | :  | '  ;   \\  ' .'  :  | \\  \\ ,'|   |  ./ '  :  | \\  \\ ,'        |   | | \\   |'  :  | \\  \\ ,'        '   :  ;.   | '_.' :;   | |  \\ '  :  | \\  \\ ,'|   | | \\   |  ___ l         :  | | :  ' ;  ");
	puts("    '   : |  : ;   \\   \\   '|  |  '  '--'  ;   : ;   |  |  '  '--'          '   : |  ; .'|  |  '  '--'          |   |  ''   ; : \\  ||   | ;\\  \\|  |  '  '--'  '   : |  ; .'/    /\\    J   :|  ; ' |  | '  ");
	puts("    |   | '  ,/     \\   `  ;|  :  :        |   ,/    |  :  :                |   | '`--'  |  :  :                '   :  |'   | '/  .':   ' | \\.'|  :  :        |   | '`--' /  ../  `..-    ,:  | : ;  ; |  ");
	puts("    ;   : ;--'       :   \\ ||  | ,'        '---'     |  | ,'                '   : |      |  | ,'                ;   |.' |   :    /  :   : :-'  |  | ,'        '   : |     \\    \\         ; '  :  `--'   \\ ");
	puts("    |   ,/            '---\" `--''                    `--''                  ;   |.'      `--''                  '---'    \\   \\ .'   |   |.'    `--''          ;   |.'      \\    \\      ,'  :  ,      .-./ ");
	puts("    '---'                                                                   '---'                                         `---`     `---'                     '---'         \"---....--'     `--`----'     ");
	puts("                                                                                                                                                                                                          ");
	puts("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	puts("//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////");
	puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
	
	puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

	Sleep(3000);
}


//ispisuje 'pobedaGrafika'
void pobedaGrafika(){
			
		puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

		puts("                                                                {_______      {____     {__ {__   {________{_____          {_       ");
		puts("                                                                {__    {__  {__    {__  {_    {__ {__      {__   {__      {_ __     ");
		puts("                                                                {__    {__{__        {__{_     {__{__      {__    {__    {_  {__    ");
		puts("                                                                {_______  {__        {__{___ {_   {______  {__    {__   {__   {__   ");
		puts("                                                                {__       {__        {__{_     {__{__      {__    {__  {______ {__  ");
		puts("                                                                {__         {__     {__ {_      {_{__      {__   {__  {__       {__ ");
		puts("                                                                {__           {____     {____ {__ {________{_____    {__         {__");
		puts("                                                                                                                                    ");

		puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");


}


//ispisuje 'porazGrafika'
void porazGrafika(){
		puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                         
		
		puts("                                                             __/\\\\\\\\\\\\\\\\\\\\\\\\\\_________/\\\\\\\\\\_________/\\\\\\\\\\\\\\\\\\_________/\\\\\\\\\\\\\\\\\\_____/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\_        ");
		puts("                                                              _\\/\\\\\\/////////\\\\\\_____/\\\\\\///\\\\\\_____/\\\\\\///////\\\\\\_____/\\\\\\\\\\\\\\\\\\\\\\\\\\__\\////////////\\\\\\__       ");
		puts("                                                               _\\/\\\\\\_______\\/\\\\\\___/\\\\\\/__\\///\\\\\\__\\/\\\\\\_____\\/\\\\\\____/\\\\\\/////////\\\\\\___________/\\\\\\/___      ");
		puts("                                                                _\\/\\\\\\\\\\\\\\\\\\\\\\\\\\/___/\\\\\\______\\//\\\\\\_\\/\\\\\\\\\\\\\\\\\\\\\\/____\\/\\\\\\_______\\/\\\\\\_________/\\\\\\/_____     ");
		puts("                                                                 _\\/\\\\\\/////////____\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\//////\\\\\\____\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\_______/\\\\\\/_______    ");
		puts("                                                                  _\\/\\\\\\_____________\\//\\\\\\______/\\\\\\__\\/\\\\\\____\\//\\\\\\___\\/\\\\\\/////////\\\\\\_____/\\\\\\/_________   ");
		puts("                                                                   _\\/\\\\\\______________\\///\\\\\\__/\\\\\\____\\/\\\\\\_____\\//\\\\\\__\\/\\\\\\_______\\/\\\\\\___/\\\\\\/___________  ");
		puts("                                                                    _\\/\\\\\\________________\\///\\\\\\\\\\/_____\\/\\\\\\______\\//\\\\\\_\\/\\\\\\_______\\/\\\\\\__/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\_ ");
		puts("                                                                     _\\///___________________\\/////_______\\///________\\///__\\///________\\///__\\///////////////_");



		puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");


}


void unesiNovuRecGrafika(){
		puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		
		puts("                    __  __                   _                                                     _ ");
		puts("                   / / / /  ___  ___   ___  (_)       ___  ___  _  __ __ __       ____ ___  ____  (_)");
		puts("                  / /_/ /  / _ \\/ -_) (_-< / /       / _ \\/ _ \\| |/ // // /      / __// -_)/ __/ _   ");
		puts("                  \\____/  /_//_/\\__/ /___//_/       /_//_/\\___/|___/ \\_,_/      /_/   \\__/ \\__/ (_)  ");
		puts("                                                                                                    ");

		puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");


}


void unesiPomocGrafika(){
		puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

		puts("                   __  __                   _                                                                          _ ");
		puts("                  / / / /  ___  ___   ___  (_)        ___  ___   __ _  ___  ____      ___ ___ _       ____ ___  ____  (_)");
		puts("                 / /_/ /  / _ \\/ -_) (_-< / /        / _ \\/ _ \\ /  ' \\/ _ \\/ __/     /_ // _ `/      / __// -_)/ __/ _   ");
		puts("                 \\____/  /_//_/\\__/ /___//_/        / .__/\\___//_/_/_/\\___/\\__/      /__/\\_,_/      /_/   \\__/ \\__/ (_)  ");
		puts("                                                   /_/                                                                   ");


		puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");


}




void visuljak0(){

	puts("\n");
	puts("      ____________________");
	puts("     | .__________________|");
	puts("     | | / / ");
	puts("     | |/ /");
	puts("     | | /");
	puts("     | |/");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     \"\"\"\"\"\"\"\"\"\"|_        |\"\"\"|");
	puts("     |\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|");
	puts("     | |        \\ \\        | |");
	puts("     : :         \\ \\       : :");
	puts("     . .          `'       . .");




}

void visuljak1(){

	puts("\n");
	puts("      ___________.._______");
	puts("     | .__________))______|");
	puts("     | | / /      ||");
	puts("     | |/ /       ||");
	puts("     | | /        ||");
	puts("     | |/         ||");
	puts("     | |          ||");
	puts("     | |         (__)");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     \"\"\"\"\"\"\"\"\"\"|_        |\"\"\"|");
	puts("     |\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|");
	puts("     | |        \\ \\        | |");
	puts("     : :         \\ \\       : :");
	puts("     . .          `'       . .");




}

void visuljak2(){

	puts("\n");
	puts("      ___________.._______");
	puts("     | .__________))______|");
	puts("     | | / /      ||");
	puts("     | |/ /       ||");
	puts("     | | /        ||.-''.");
	puts("     | |/         |/  _  \\");
	puts("     | |          ||  `/,|");
	puts("     | |          (\\\\`_.'");
	puts("     | |           `--' ");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     \"\"\"\"\"\"\"\"\"\"|_        |\"\"\"|");
	puts("     |\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|");
	puts("     | |        \\ \\        | |");
	puts("     : :         \\ \\       : :");
	puts("     . .          `'       . .");




}

void visuljak3(){

	puts("\n");
	puts("      ___________.._______");
	puts("     | .__________))______|");
	puts("     | | / /      ||");
	puts("     | |/ /       ||");
	puts("     | | /        ||.-''.");
	puts("     | |/         |/  _  \\");
	puts("     | |          ||  `/,|");
	puts("     | |          (\\\\`_.'");
	puts("     | |         .-`--'.");
	puts("     | |         Y . . Y");
	puts("     | |          |   |");
	puts("     | |          | . |");
	puts("     | |          |   | ");
	puts("     | |            '");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     \"\"\"\"\"\"\"\"\"\"|_        |\"\"\"|");
	puts("     |\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|");
	puts("     | |        \\ \\        | |");
	puts("     : :         \\ \\       : :");
	puts("     . .          `'       . .");




}



void visuljak4(){

	puts("\n");
	puts("      ___________.._______");
	puts("     | .__________))______|");
	puts("     | | / /      ||");
	puts("     | |/ /       ||");
	puts("     | | /        ||.-''.");
	puts("     | |/         |/  _  \\");
	puts("     | |          ||  `/,|");
	puts("     | |          (\\\\`_.'");
	puts("     | |         .-`--'.");
	puts("     | |        /Y . . Y");
	puts("     | |       // |   |");
	puts("     | |      //  | . |");
	puts("     | |     ')   |   | ");
	puts("     | |            '");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     \"\"\"\"\"\"\"\"\"\"|_        |\"\"\"|");
	puts("     |\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|");
	puts("     | |        \\ \\        | |");
	puts("     : :         \\ \\       : :");
	puts("     . .          `'       . .");

}


void visuljak5(){

	puts("\n");
	puts("      ___________.._______");
	puts("     | .__________))______|");
	puts("     | | / /      ||");
	puts("     | |/ /       ||");
	puts("     | | /        ||.-''.");
	puts("     | |/         |/  _  \\");
	puts("     | |          ||  `/,|");
	puts("     | |          (\\\\`_.'");
	puts("     | |         .-`--'.");
	puts("     | |        /Y . . Y\\");
	puts("     | |       // |   |  \\\\");
	puts("     | |      //  | . |   \\\\");
	puts("     | |     ')   |   |    (`");
	puts("     | |            '");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     | |");
	puts("     \"\"\"\"\"\"\"\"\"\"|_        |\"\"\"|");
	puts("     |\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|");
	puts("     | |        \\ \\        | |");
	puts("     : :         \\ \\       : :");
	puts("     . .          `'       . .");

}



void visuljak6(){

	puts("\n");
	puts("      ___________.._______");
	puts("     | .__________))______|");
	puts("     | | / /      ||");
	puts("     | |/ /       ||");
	puts("     | | /        ||.-''.");
	puts("     | |/         |/  _  \\");
	puts("     | |          ||  `/,|");
	puts("     | |          (\\\\`_.'");
	puts("     | |         .-`--'.");
	puts("     | |        /Y . . Y\\");
	puts("     | |       // |   |  \\\\");
	puts("     | |      //  | . |   \\\\");
	puts("     | |     ')   |   |    (`");
	puts("     | |          ||'");
	puts("     | |          ||");
	puts("     | |          ||");
	puts("     | |          ||");
	puts("     | |         / |");
	puts("     \"\"\"\"\"\"\"\"\"\"|_`-'     |\"\"\"|");
	puts("     |\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|");
	puts("     | |        \\ \\        | |");
	puts("     : :         \\ \\       : :");
	puts("     . .          `'       . .");

}



void visuljak7(){

	puts("\n");
	puts("      ___________.._______");
	puts("     | .__________))______|");
	puts("     | | / /      ||");
	puts("     | |/ /       ||");
	puts("     | | /        ||.-''.");
	puts("     | |/         |/  _  \\");
	puts("     | |          ||  `/,|");
	puts("     | |          (\\\\`_.'");
	puts("     | |         .-`--'.");
	puts("     | |        /Y . . Y\\");
	puts("     | |       // |   |  \\\\");
	puts("     | |      //  | . |   \\\\");
	puts("     | |     ')   |   |    (`");
	puts("     | |          ||'||");
	puts("     | |          || ||");
	puts("     | |          || ||");
	puts("     | |          || ||");
	puts("     | |         / | | \\");
	puts("     \"\"\"\"\"\"\"\"\"\"|_`-' `-' |\"\"\"|");
	puts("     |\"|\"\"\"\"\"\"\"\\ \\       '\"|\"|");
	puts("     | |        \\ \\        | |");
	puts("     : :         \\ \\       : :");
	puts("     . .          `'       . .");

}