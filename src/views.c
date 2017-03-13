/* Este arquivo contém as funções que apresentam informações na tela */

void view_partial_owners(){
  node_owner * each;

  printf(BYEL"\t");
  printf("%-10s", "ID");
  printf("%-5s", "UF");
  printf("%-40s", "NOME");
  printf("%-25s", "CPF");
  printf("\n\n");

  for(each = owners->start; each != NULL; each=each->next){
    printf(BWHT"\t");
    printf("%-10d", each->data.id);
    printf("%-5s", each->data.state);
    printf("%-40s", each->data.name);
    printf("%-25s", each->data.cpf);
    printf("\n");
  }
}

void view_add_owner(){
  clear();
  printf("\n");
  printf(BCYN "\tPROPRIETÁRIOS DE CARROS - ADICIONAR PROPRIETÁRIO\n\n" RESET);
  /* receber name */
  printf(BYEL "\tNOME\n\n");
  printf(BWHT "\t- ");
  get_string(add_owner->name, OWNER_NAME_LENGTH);
  printf("\n");

  /* receber name */
  printf(BYEL "\tCPF\n\n");
  printf(BWHT "\t- ");
  get_string(add_owner->cpf, OWNER_CPF_LENGTH);
  printf("\n");

  /* receber endereço */
  printf(BYEL "\tENDEREÇO\n\n");
  printf(BWHT "\t- ");
  get_string(add_owner->address, OWNER_ADDR_LENGTH);
  printf("\n");
  //
  // /* Receber Bairro */
  printf(BYEL "\tBAIRRO\n\n");
  printf(BWHT "\t- ");
  get_string(add_owner->neighborhood, OWNER_NBHD_LENGTH);
  printf("\n");

  // input zip_code
  printf(BYEL "\tCEP\n\n");
  printf(BWHT "\t- ");
  get_string(add_owner->zip_code, OWNER_ZPCD_LENGTH);
  printf("\n");

  // input city
  printf(BYEL "\tCIDADE\n\n");
  printf(BWHT "\t- ");
  get_string(add_owner->city, OWNER_CITY_LENGTH);
  printf("\n");

  // input state
  printf(BYEL "\tESTADO (UF)\n\n" RESET);
  printf(BWHT "\t- ");
  get_string(add_owner->state, OWNER_STAT_LENGTH);
  printf("\n");

  //
  // /* Exibir Opções de Cadastro */
  printf(BRED "\t[a] Salvar\t");
  printf(BRED "\t[b] Cancelar\n");
  printf(BWHT "\n\n\n");

}

void view_car(){
  clear();
  printf("\n");
  printf(BCYN "\tPROPRIETÁRIOS DE CARROS - DETALHES CARRO\n\n\n" RESET);

  printf(BRED"\t"); // trocar por leitura
  printf("DADOS DO CARRO"); // trocar por leitura
  printf("\n\n\n"); //trocar por leitura

  printf(BYEL"\t");
  printf("%-10s", "ID");
  printf("%-40s", "NOME DO PROPRIETÁRIO");
  printf("%s", "CPF DO PROPRIETÁRIO");
  printf("\n\n");

  printf(BWHT"\t");
  printf("%-10d", viewing_car->data.id);
  printf("%-40s", viewing_owner->data.name);
  printf("%s", viewing_owner->data.cpf);
  printf("\n\n");

  printf(BYEL"\t");
  printf("%-20s", "MARCA");
  printf("%-30s", "MODELO");
  printf("%-20s", "PLACA");
  printf("%s", "RENAVAM");
  printf("\n\n");

  printf(BWHT"\t");
  printf("%-20s", viewing_car->data.manufacturer);
  printf("%-30s", viewing_car->data.model);
  printf("%-20s", viewing_car->data.registration_plate);
  printf("%s", viewing_car->data.renavam);

  printf("\n\n");

  printf(BRED "\t");
  printf("[%c] Editar\t", EDIT_CAR);
  printf("[%c] Excluir\t", DELETE_CAR);
  printf("[%c] Voltar\t", BACK_TO_OWNER);
  printf(RESET);

  printf("\n\n\n");
}

void view_home(){
  clear();
  printf("\n");
  printf(BCYN "\tPROPRIETÁRIOS DE CARROS\n\n\n" RESET);

  // render partial
  view_partial_owners();

  printf("\n\n");

  printf(BRED "\t");
  printf("[%c] Adicionar\t", ADD_OWNER);
  printf("[%c] Consultar\t", SEARCH_OWNER);
  printf("[%c] Sair\t", EXIT);
  printf("\n\n\n");

  printf(BWHT);
}

void view_owner(){
  clear();
  printf("\n");
  printf(BCYN "\tPROPRIETÁRIOS DE CARROS - DETALHES PROPRIETÁRIO\n\n\n" RESET);

  printf(BRED"\t"); // trocar por leitura
  printf("DADOS DO PROPRIETÁRIO"); // trocar por leitura
  printf("\n\n\n"); //trocar por leitura

  printf(BYEL"\t");
  printf("%-10s", "ID");
  printf("%-40s", "NOME");
  printf("%-25s", "CPF");
  printf("%s", "CEP");
  printf("\n\n");

  printf(BWHT"\t");
  printf("%-10d", viewing_owner->data.id);
  printf("%-40s", viewing_owner->data.name);
  printf("%-25s", viewing_owner->data.cpf);
  printf("%s", viewing_owner->data.zip_code);
  printf("\n\n");

  printf(BYEL"\t");
  printf("%-51s", "ENDEREÇO");
  printf("%-25s", "BAIRRO");
  printf("%-40s", "CIDADE (UF)");
  printf("\n\n");

  printf(BWHT"\t");
  printf("%-51s", viewing_owner->data.address);
  printf("%-25s", viewing_owner->data.neighborhood);
  printf("%s (%s)", viewing_owner->data.city, viewing_owner->data.state);
  printf("\n\n\n");

  printf(BRED"\t"); // trocar por leitura
  printf("CARROS DO PROPRIETÁRIO"); // trocar por leitura
  printf("\n\n\n"); //trocar por leitura

  printf(BYEL"\t");
  printf("%-20s", "MARCA");
  printf("%-30s", "MODELO");
  printf("%-20s", "PLACA");
  printf("%s", "RENAVAM");
  printf("\n\n");

  for(node_car * each = cars->start; each != NULL; each=each->next){
    if(viewing_owner->data.id == each->data.owner){
      printf(BWHT"\t");
      printf("%-20s", each->data.manufacturer);
      printf("%-30s", each->data.model);
      printf("%-20s", each->data.registration_plate);
      printf("%s", each->data.renavam);
      printf("\n");
    }
  }

  printf("\n\n");

  printf(BRED "\t");
  printf("[%c] Editar\t", EDIT_OWNER);
  printf("[%c] Excluir\t", DELETE_OWNER);
  printf("[%c] Adicionar Carro\t", ADD_CAR);
  printf("[%c] Consultar Carro\t", SEARCH_CAR);
  printf("[%c] Home\t", BACK_TO_HOME);
  printf(RESET);

  printf("\n\n\n");
}

void view_search_owner(){
  clear();
  printf("\n");
  printf(BCYN "\tPROPRIETÁRIOS DE CARROS - CONSULTAR PROPRIETÁRIO\n\n\n");

  printf(BYEL "\tCPF DO PROPRIETÁRIO\n\n");
  printf(BWHT "\t- ");
  get_string(cpf, OWNER_CPF_LENGTH);

  printf("\n\n");

  printf(BRED "\t");
  printf("[%c] Buscar\t", CONFIRM_SEARCH);
  printf("[%c] Cancelar\t", CANCEL_SEARCH);
  printf(RESET);

  printf("\n\n\n");
}

void view_search_owner_not_found(){
  clear();
  printf("\n");
  printf(BCYN "\tPROPRIETÁRIOS DE CARROS - CONSULTAR PROPRIETÁRIO\n\n\n");

  printf(BRED "\tNÃO FOI ENCONTRADO NENHUM PROPRIETÁRIO PELO CPF INFORMADO\n\n");
  printf(BWHT "\t- %s", cpf);
  printf("\n\n");

  printf(BRED "\t");
  printf("[%c] Nova busca\t", NEW_SEARCH);
  printf("[%c] Cancelar\t", CANCEL_SEARCH);
  printf(RESET);

  printf("\n\n\n");
}
void view_search_car(){
  clear();
  printf("\n");
  printf(BCYN "\tPROPRIETÁRIOS DE CARROS - CONSULTAR CARRO\n\n\n");

  printf(BYEL "\tPROPRIETÁRIO (CPF)\n\n");
  printf(BWHT "\t- %s (%s)", viewing_owner->data.name, viewing_owner->data.cpf);

  printf("\n\n");
  printf(BYEL "\tPLACA DO CARRO\n\n");
  printf(BWHT "\t- ");
  get_string(registration_plate, CAR_RPLT_LENGTH);

  printf("\n\n");

  printf(BRED "\t");
  printf("[%c] Buscar\t", CONFIRM_SEARCH);
  printf("[%c] Cancelar\t", CANCEL_SEARCH);
  printf(RESET);

  printf("\n\n\n");
}

void view_search_car_not_found(){
  clear();
  printf("\n");
  printf(BCYN "\tPROPRIETÁRIOS DE CARROS - CONSULTAR CARRO");
  printf("\n\n\n");
  printf(BRED "\tNÃO FOI ENCONTRADO NENHUM CARRO COM A PLACA INFORMADA PARA O PROPRIETÁRIO");
  printf("\n\n");
  printf(BYEL "\tPROPRIETÁRIO");
  printf("\n\n");
  printf(BWHT "\t- %s (%s)", viewing_owner->data.name, viewing_owner->data.cpf);
  printf("\n\n");
  printf(BYEL "\tPLACA");
  printf("\n\n");
  printf(BWHT "\t- %s", registration_plate);
  printf("\n\n");

  printf(BRED "\t");
  printf("[%c] Nova busca\t", NEW_SEARCH);
  printf("[%c] Cancelar\t", CANCEL_SEARCH);
  printf(RESET);

  printf("\n\n\n");
}

void view_edit_owner(){
  clear();
  printf("\n");
  printf(BCYN "\tPROPRIETÁRIOS DE CARROS - EDITAR PROPRIETÁRIO\n\n");
  /* receber name */
  printf(BYEL "\tNOME ");
  printf(WHT "[%s]", viewing_owner->data.name);
  printf("\n\n");
  printf(BWHT "\t- ");
  get_string(viewing_owner->data.name, OWNER_NAME_LENGTH);
  printf("\n");

  printf(BYEL "\tCPF ");
  printf(WHT "[%s]", viewing_owner->data.cpf);
  printf("\n\n");
  printf(BWHT "\t- ");
  get_string(viewing_owner->data.cpf, OWNER_CPF_LENGTH);
  printf("\n");

  printf(BYEL "\tENDEREÇO ");
  printf(WHT "[%s]", viewing_owner->data.address);
  printf("\n\n");
  printf(BWHT "\t- ");
  get_string(viewing_owner->data.address, OWNER_ADDR_LENGTH);
  printf("\n");

  printf(BYEL "\tBAIRRO ");
  printf(WHT "[%s]", viewing_owner->data.neighborhood);
  printf("\n\n");
  printf(BWHT "\t- ");
  get_string(viewing_owner->data.neighborhood, OWNER_NBHD_LENGTH);
  printf("\n");

  printf(BYEL "\tCEP ");
  printf(WHT "[%s]", viewing_owner->data.zip_code);
  printf("\n\n");
  printf(BWHT "\t- ");
  get_string(viewing_owner->data.zip_code, OWNER_ZPCD_LENGTH);
  printf("\n");

  printf(BYEL "\tCIDADE ");
  printf(WHT "[%s]", viewing_owner->data.city);
  printf("\n\n");
  printf(BWHT "\t- ");
  get_string(viewing_owner->data.city, OWNER_CITY_LENGTH);
  printf("\n");

  printf(BYEL "\tESTADO (UF) ");
  printf(WHT "[%s]", viewing_owner->data.state);
  printf("\n\n");
  printf(BWHT "\t- ");
  get_string(viewing_owner->data.state, OWNER_STAT_LENGTH);
  printf("\n\n\n");

  printf(BRED "\t");
  printf("[%c] Salvar\t", 'a');
  printf("[%c] Cancelar\t", 'b');
  printf("\n\n\n");
  printf(BWHT);

}

void view_add_car(){
  clear();
  printf("\n");
  printf(BCYN "\tPROPRIETÁRIOS DE CARROS - ADICIONAR CARRO\n\n" RESET);
  /* receber name */
  printf(BYEL "\tMARCA ");
  printf("\n\n");
  printf(BWHT "\t- ");
  get_string(add_car->manufacturer, CAR_MANU_LENGTH);
  printf("\n");

  printf(BYEL "\tMODELO ");
  printf("\n\n");
  printf(BWHT "\t- ");
  get_string(add_car->model, CAR_MODE_LENGTH);
  printf("\n");

  printf(BYEL "\tPLACA ");
  printf("\n\n");
  printf(BWHT "\t- ");
  get_string(add_car->registration_plate, CAR_RPLT_LENGTH);
  printf("\n");

  printf(BYEL "\tRENAVAM ");
  printf("\n\n");
  printf(BWHT "\t- ");
  get_string(add_car->renavam, CAR_RENA_LENGTH);

  printf("\n\n\n");

  printf(BRED "\t");
  printf("[%c] Salvar\t", 'a');
  printf("[%c] Cancelar\t", 'b');
  printf("\n\n\n");
  printf(BWHT);

}

void view_edit_car(){
  clear();
  printf("\n");
  printf(BCYN "\tPROPRIETÁRIOS DE CARROS - EDITAR CARRO\n\n" RESET);

  printf(BYEL "\tMARCA ");
  printf(WHT "[%s]", viewing_car->data.manufacturer);
  printf("\n\n");
  printf(BWHT "\t- ");
  get_string(viewing_car->data.manufacturer, CAR_MANU_LENGTH);
  printf("\n");

  printf(BYEL "\tMODELO ");
  printf(WHT "[%s]", viewing_car->data.model);
  printf("\n\n");
  printf(BWHT "\t- ");
  get_string(viewing_car->data.model, CAR_MODE_LENGTH);
  printf("\n");

  printf(BYEL "\tPLACA ");
  printf(WHT "[%s]", viewing_car->data.registration_plate);
  printf("\n\n");
  printf(BWHT "\t- ");
  get_string(viewing_car->data.registration_plate, CAR_RPLT_LENGTH);
  printf("\n");

  printf(BYEL "\tRENAVAM ");
  printf(WHT "[%s]", viewing_car->data.renavam);
  printf("\n\n");
  printf(BWHT "\t- ");
  get_string(viewing_car->data.renavam, CAR_RENA_LENGTH);

  printf("\n\n\n");

  printf(BRED "\t");
  printf("[%c] Salvar\t", CONFIRM_EDIT_CAR);
  printf("[%c] Cancelar\t", CANCEL_EDIT_CAR);
  printf("\n\n\n");
  printf(BWHT);

}

void view_delete_car(){
  clear();
  printf("\n");
  printf(BCYN "\tPROPRIETÁRIOS DE CARROS - EXCLUIR CARRO\n\n\n" RESET);

  printf(BYEL"\t");
  printf("VOCÊ TEM CERTEZA QUE DESEJA EXCLUIR O CARRO?");
  printf("\n\n");
  printf(BWHT "\t- %s - %s (%s)", viewing_car->data.manufacturer, viewing_car->data.model, viewing_car->data.registration_plate);
  printf("\n\n\n");

  printf(BRED "\t");
  printf("[%c] Excluir\t", 'a');
  printf("[%c] Cancelar\t", 'b');
  printf("\n\n\n");
  printf(BWHT);

}

void view_delete_owner(){
  clear();
  printf("\n");
  printf(BCYN "\tPROPRIETÁRIOS DE CARROS - EXCLUIR\n\n\n" RESET);

  printf(BYEL"\t");
  printf("VOCÊ TEM CERTEZA QUE DESEJA EXCLUIR O PROPRIETÁRIO?");
  printf("\n\n");
  printf(BWHT "\t- %s (%s)", viewing_owner->data.name, viewing_owner->data.cpf);
  printf("\n\n\n");

  printf(BRED "\t");
  printf("[%c] Excluir\t", 'a');
  printf("[%c] Cancelar\t", 'b');
  printf("\n\n\n");
  printf(BWHT);

}


void view_exit(){
  clear();
  printf("\n");
  save_owners();
  save_cars();
  printf("\n\n");
  printf(RESET);
}
