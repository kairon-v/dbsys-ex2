/* Este arquivo contém as funções de estrutura de dados */

struct _owner{
	int id;
	char name[OWNER_NAME_LENGTH];
	char cpf[OWNER_CPF_LENGTH];
	char address[OWNER_ADDR_LENGTH];
	char neighborhood[OWNER_NBHD_LENGTH];
	char zip_code[OWNER_ZPCD_LENGTH];
	char city[OWNER_CITY_LENGTH];
	char state[OWNER_STAT_LENGTH];
};

struct _car{
	int id;
	int owner;
	char manufacturer[CAR_MANU_LENGTH];
	char model[CAR_MODE_LENGTH];
	char registration_plate[CAR_RPLT_LENGTH];
	char renavam[CAR_RENA_LENGTH];
};


char get_option(){

  char option;
  printf("\t");
  option = getchar();

  if(option == '\n'){
    lineup();
    clearline();
    get_option();
  }

	// get blank space
	getchar();

  return option;
}
