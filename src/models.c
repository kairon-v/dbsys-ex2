
void load_owners(){
	FILE * fp = fopen(OWNERS_FILE, "rb");
	if(fp == NULL){
		printf(BRED"\tNÃO FOI POSSÍVEL LER O ARQUIVO DE PROPRIETÁRIOS.\n"RESET);
		return;
	}

 	owner load;
 	while(fread(&load, sizeof(owner), 1, fp) == 1) {
 		insert_owner(&load);
 	}
 	fclose(fp);
}

void load_cars(){
	FILE * fp = fopen(CARS_FILE, "rb");
	if(fp == NULL){
		printf(BRED"\tNÃO FOI POSSÍVEL LER O ARQUIVO DE CARROS.\n"RESET);
		return;
	}

 	car load;
 	while(fread(&load, sizeof(car), 1, fp) == 1) {
 		insert_car(&load);
 	}
 	fclose(fp);
}

void save_owners(){
	printf(BYEL"\t PROPRIETÁRIOS \n\n");
	printf(BBLU"\t - SALVANDO... \n");
	FILE *fp;
	node_owner * each;

 	fp = fopen(OWNERS_FILE_TEMP , "wb");
 	if(fp == NULL){
    printf(BRED"\tNÃO FOI POSSÍVEL INICIAR O ARQUIVO DE GRAVAÇÃO DE PROPRIETÁRIOS.\n");
	  return;
	}

	/* Grava a lista no arquivo */
	for(each = owners->start; each != NULL; each=each->next){
  	fwrite(&each->data, sizeof(owner), 1, fp);
	}

 	fclose(fp);

 	if(rename(OWNERS_FILE_TEMP, OWNERS_FILE) != 0){
 		printf(BRED"\tNÃO FOI POSSÍVEL RENOMEAR O ARQUIVO DE GRAVAÇÃO DE PROPRIETÁRIOS.\n");
 		return;
	}

	printf(BGRN"\t - SALVO COM ÊXITO!\n\n");

}

void save_cars(){

	printf(BYEL"\t CARROS \n\n");
	printf(BBLU"\t - SALVANDO...\n");

	FILE *fp;
	node_car * each;

 	fp = fopen(CARS_FILE_TEMP , "wb");
 	if(fp == NULL){
		printf(BRED"\tNÃO FOI POSSÍVEL INICIAR O ARQUIVO DE GRAVAÇÃO DE CARROS.\n");
		return;
	}

	/* Grava a lista no arquivo */
	for(each = cars->start; each != NULL; each=each->next){
  	fwrite(&each->data, sizeof(car), 1, fp);
	}

 	fclose(fp);

 	if(rename(CARS_FILE_TEMP, CARS_FILE) != 0){
 		printf(BRED"\tNÃO FOI POSSÍVEL RENOMEAR O ARQUIVO DE GRAVAÇÃO DE CARROS.\n");
 		return;
	}

	printf(BGRN"\t - SALVO COM ÊXITO!");

}
