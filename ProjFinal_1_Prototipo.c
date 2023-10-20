#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
    Teste para tela de cadastro
*/

int main()
{
    int tentlog = 0, cont_fun = 0, cont_cli = 0, n = 0, m = 0, a = 1, ret_lo_c = 0, ret_lo_f = 0; 
    
    int cmp_cli = 0, cmp_fun = 0, v_chp = 0, nc, fn = 0, cn = 0, ret_Log = 0, arm_cli = 0, arm_fun = 0;

    //Essas variaveis serão utilizada para verificar se o usuario esqueceu sua senha ou não, dando a possibilidade de alterar a senha
    int fun1 = 0, fun2 = 0, fun3 = 0, fun4 = 0, cli1 = 0, cli2 = 0, cli3 = 0;

    char efoc, rd, cad, opt, alteraSen;

    //As variaveis 'n', 'm' e 'a' nao possuem nome especifico, mas falarei o que essas fazem

    //'n': e a variavel responsavel pelo endereçamento do login e senha dentro da matriz.
    //'m': essa variavel por sua diz qual matriz endereçar o login e senha, funciona como um contador de matrizes disponiveis (não possui dados armazenados)
    //'a': é a variavel para fazer os loops com 'do while'.


    // Vetores que serao necessarios para o cadastro

    char senc[50]; // Vetor para confirmacao da senha

    //Vetores de login e senha para tela de login, serve para compara com os dados cadastrados
    char login[50];
    char senha[50];

    // Vetores responsavel pelo armazenamento do dados cadastrados LOGIN e SENHA
    
    //Vetores para cadastro dos FUNCIONARIOS
    char scf1[2][50]; 
    char scf2[2][50];
    char scf3[2][50];
    char scf4[2][50];

    //Vetores para cadastro dos CLIENTES
    char scc1[2][50];
    char scc2[2][50];
    char scc3[2][50];

    //Aqui declaro um endereço para a funcao 'goto' para fazer um ciclo entre as telas que serao abordadas
    T_inicio:

    //Tela Inicio eu recebo o usuario com as boas vindas e mostro ao usuario as opcoes
    printf("---------------------------\n");
    printf("\n\t Welcome\n");
    printf("\n---------------------------\n");

    //Loop para caso o usuario digite algo diferente do que solicitado '1, 2 ou 3', utilizarei bastante esse loop
    do {

        a = 1;

        while (opt == '\n'){ //serve para limpar o buffer do teclado quando este for igual a tecla enter
            getchar();
        }

        printf("\n  1) Log in\n");
        printf("\n  2) Sign up\n");
        printf("\n\n  3) Exit\n");
        printf("\nChoose one option: ");
        scanf(" %c[^\n]", &opt);
        getchar();

        //Separo cada opcao pelo switch case desde login ate exit
        switch (opt){

            case '1':
                //Antes de ter acesso a tela de login verifico se há ao menos um cliente ou funcionario cadastrado
                if (arm_cli > 0 || arm_fun > 0){
                    Log:                //Por conta desse endereço para o goto para que tudo seja executado novamente preciso zerar seus valores
                    ret_Log = 0;        //Essa variavel é zerada para que funcionamento do loop seja possivel 
                    ret_lo_c = 0;       //Essa variavel e utilizada para caso o usuario selecionar 'CLIENTE' e o mesmo nao ter registro, indo para a area de cadastro de Cliente
                    ret_lo_f = 0;       //Essa variavel e utilizada para caso o usuario selecionar 'FUNCIONARIO' e o mesmo nao ter registro, indo para a area de cadastro de Funcionario
                    tentlog = 0;        //Essa variavel e a quantidade de vezes que o usuario pode tentar logar, sendo 3, preciso zerar para que no ciclo de telas essa possa ser testada de maneira correta

                    /*
                        As variaveis abaixo verificam se o login ja foi cadastrado e precisa ser reinicializado para que assim
                        funcione adequadamente o loop
                    */
                    fun1 = 0;
                    fun2 = 0;
                    fun3 = 0;
                    fun4 = 0;
                    cli1 = 0;
                    cli2 = 0;
                    cli3 = 0;

                    printf("\n  Welcome, you chose - Log in\n");
                    printf("\nYou have two optaions to choose:\n");

                    //Loop utilizado para caso digite algo diferente do que solicitado
                    do{
                        a = 1;
                        while (efoc == '\n'){
                            getchar();
                        }
        
                        printf("\n   'F' - employee\n\n   'C' - client\n\n");
                        printf("which one are you: ");
                        scanf(" %c[^\n]", &efoc);
                        getchar();

                        if ((efoc == 'F' || efoc == 'f') && (arm_fun > 0)){ //Verifica se foi selecionado funcionario e se há algum funcionario já registrado

                            Log_f:

                            printf("\n  EMPLOYEE'S LOGIN\n");
                            //Loop para comparar o login e senha digitados com os salvos na area de cadastro, e repetido caso login/usuario ou senha estejam errados
                            do{

                                //Loop caso o login tenha menos de 3 caracteres
                                do{

                                    printf("\nType your login:\n");
                                    printf("\nLogin> ");
                                    fgets(login, 50, stdin);  //funcao que le o que foi digitado pelo teclado e atribui a variavel login.

                                    //utilizo esse loop para remover o 'enter' salvo na variavel
                                    while (login[v_chp] != '\0'){
                                        if (login[v_chp] == '\n'){
                                            login[v_chp] = '\0';
                                        }
                                        v_chp++;
                                    }
                                    v_chp = 0;

                                    //Caso o login/Usuario tenha menos de tres caracteres, será notificado a utilizar mais caracteres
                                    if (strlen(login) < 3){
                                        printf("\nYour login has to have more than 2 characters!\n");
                                    }
                                }while(strlen(login) < 3);
                                
                                //Loop caso a senha nao tenha pelo menos 8 caracteres
                                do{
                                    printf("Senha> ");
                                    fgets(senha, 50, stdin);  //funcao que le o que foi digitado pelo teclado e atribui a variavel senha.

                                    //Como citado anteriormente no login, utilizo esse loop para remover o 'enter' da variavel senha
                                    while (senha[v_chp] != '\0'){
                                        if (senha[v_chp] == '\n'){
                                            senha[v_chp] = '\0';
                                        }
                                        v_chp++;
                                    }
                                    v_chp = 0;

                                    //Envio uma mensagem alertando que a senha deve possuir mais de oito caracteres
                                    if (strlen(senha) < 8){
                                        printf("\nYour password has to have more than 8 characters!\n");
                                    }
                                }while (strlen(senha) < 8);

                                
                                cmp_fun = 1;    //Variavel de comparaçao é igualada ao valor inicial para ser possivel a comparacao quando o loop se repetir

                                //Laço de repeticao para compara o login e senha de cada matriz que armazena o registro dos Funcionarios
                                for (m = 0; m <= fn; m++){

                                    //Aqui faço a checagem de qual matriz avaliar e seus respectivos dados -> LOGIN e SENHA 
                                    if (m == 0){
                                        if (!strcmp(login, scf1[0]) && !strcmp(senha, scf1[1])){
                                            printf("\n   Welcome %s\n", login);
                                            cmp_fun = 0; //Quando a variavel de comparacao e zerada o loop e rompido
                                            break;
                                        }
                                        //Aqui se faz a contagem de quantas vezes o usuário acertou o login mas errou a senha o mesmo é feita para as próximas comparações
                                        else if (!strcmp(login, scf1[0]) && strcmp(senha, scf1[1]) != 0){
                                            fun1++;
                                        }
                                    }
                                    else if (m == 1){
                                        if (!strcmp(login, scf2[0]) && !strcmp(senha, scf2[1])){
                                            printf("\n   Welcome %s\n", login);
                                            cmp_fun = 0;
                                            break;
                                        }
                                        else if (!strcmp(login, scf2[0]) && strcmp(senha, scf2[1]) != 0){
                                            fun2++;
                                        }
                                    }
                                    else if (m == 2){
                                        if (!strcmp(login, scf3[0]) && !strcmp(senha, scf3[1])){
                                            printf("\n   Welcome %s\n", login);
                                            cmp_fun = 0;
                                            break;
                                        }
                                        else if (!strcmp(login, scf3[0]) && strcmp(senha, scf3[1]) != 0){
                                            fun3++;
                                        }
                                    }
                                    else if (m == 3){
                                        if (!strcmp(login, scf4[0]) && !strcmp(senha, scf4[1])){
                                            printf("\n   Welcome %s\n", login);
                                            cmp_fun = 0;
                                            break;
                                        }
                                        else if (!strcmp(login, scf4[0]) && strcmp(senha, scf4[1]) != 0){
                                            fun4++;
                                        }
                                    }
                                    
                                }

                                //Caso a variavel permanecer com seu valor inicial e mostrada a mensagem abaixo e o loop se repete
                                //É feita a comparação nessas duas condições verificando se há ou não o login registrado no sistema
                                //Se não houver é informado ao usuário, caso houver, mas a senha estiver errada é mostrado ao usuário
                                if (cmp_fun == 1 && (fun1 == 0 && fun2 == 0 && fun3 == 0 && fun4 == 0)){  
                                    printf("\nUser wasn't fond. There is no user registered with this count!\n");
                                    tentlog++;  //É incrementado a variavel que conta as tentativas do usuario, sendo permitida apenas 3 tentativas
                                }
                                else{
                                    printf("\nWrong password!\n");
                                    tentlog++;
                                }

                            }while (cmp_fun == 1 && tentlog < 3);
                            
                            /*
                                Nessa condição abaixo é para caso o usuário tiver digitado durante as três tentativas um
                                nome que não foi registrado é oferecido a oportunidade de cadastro a esse usuário, claro
                                tendo em vista nosso sistema que comporta um número muito limitado para registro de cadastros.

                                Caso o usuário não queira ele será redirecionado novamente para a tela inicial.
                            */
                            if (tentlog >= 2 && cmp_fun == 1 && (fun1 == 0 && fun2 == 0 && fun3 == 0 && fun4 == 0)){  //Caso o numero de tentativas se exceda e mostrado a mensagem de que o usuario nao foi encontrado e que acabou as suas tentativas
                                printf("\nYou had three chances to try log in, but your user's login wasn't find!\n");

                                //Se ainda restar espaço, ou seja, haver uma matriz que nao foi utilizada este programa pergunta se o usuario nao gostaria de cadastrar-se como funcionario
                                if (fn < 3){
                                    rd = '\0';

                                    //Este loop é para que se o usuario digite algo que nao for 'y' ou 'n' repita a pergunta se quer ou nao ir para area de registro
                                    do{

                                        while (rd == '\n'){
                                            getchar();
                                        }

                                        printf("\nWould you like to go to register's area[Y/n]: ");
                                        scanf(" %c[^\n]", &rd);
                                        getchar();

                                    }while (rd != 'Y' && rd != 'y' && rd != 'N' && rd != 'n'); 

                                    //Caso a resposta da questao seja sim ele sera envia para area de cadastro
                                    if (rd == 'Y' || rd == 'y'){
                                        printf("\nOkay, you'll be sent to register's area!\n");
                                        ret_Log++;  //Essa variavel indicara que apos feito o cadastro do funcionario devera retornar direto para o login
                                        ret_lo_f++; //Essa por sua vez especifica que o retorno devera ser na opcao dos Funcionarios.
                                        goto Reg_fun;
                                    }
                                    //Caso nao ele retornara para a Tela inicial
                                    else{
                                        printf("\nOkay, Thank you!\n\n");
                                        goto T_inicio;
                                    }
                                    rd = '\0';
                                }

                                // Se nao ouver espaço ele retorna para a tela de inicio
                                goto T_inicio;
                            }


                            /*
                                A condição abaixo é para quando o usuário durante as três tentativas digitar
                                um mesmo nome de usuário já, porém com a senha incorreta, caso isso ocorra, será
                                ofertado a opção para trocar a senha, onde ele vai refazer sua senha e confirmá-la
                                e após feita a alteração da senha o mesmo será redirecionado novamente para a tela
                                de login. Ao negar a opção de redefinir a sua senha o usuário será redirecionado para
                                a tela de login da mesma forma
                            */

                            else if (tentlog >= 2 && (fun1 > 2 || fun2 > 2 || fun3 > 2 || fun4 > 2)){

                                a = 1;

                                do{ 
                                    while(alteraSen == '\n'){
                                        getchar();
                                    }

                                    printf("\nDo you intend to change your password[Y/n] ");
                                    scanf(" %c[^\n]", &alteraSen);
                                    getchar();

                                    if (alteraSen != 'Y' && alteraSen != 'y' && alteraSen != 'N' && alteraSen != 'n'){
                                        printf("\nInvalid option\n");
                                    }

                                }while(alteraSen != 'Y' && alteraSen != 'y' && alteraSen != 'N' && alteraSen != 'n');

                                if (alteraSen == 'Y' || alteraSen == 'y'){

                                    if (fun1 > 2){

                                        do{

                                            printf("\nNew password> "); 
                                            fgets(scf1[1], 50, stdin); 
                                            while (scf1[1][v_chp] != '\0'){
                                                if (scf1[1][v_chp] == '\n'){
                                                    scf1[1][v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (strlen(scf1[1]) < 8){
                                                printf("\nYour password has to have 8 characters!\n\n");
                                            }

                                        }while (strlen(scf1[1]) < 8);

                                        do{

                                            a = 1;
                                            printf("\nConfirm your new password: "); 
                                            fgets(senc, 50, stdin); 

                                            while (senc[v_chp] != '\0'){
                                                if (senc[v_chp] == '\n'){
                                                    senc[v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            // Comparo a senha do vetor senc (confirma senha) com o sc (vetor dos dados cadastrados)
                                            if (!strcmp(senc, scf1[1])){  // Se ambos forem iguais
                                                printf("\nNew password saved with success!\n"); // Falo que a nova senha foi salva
                                                printf("\nTry to login again!\n");
                                                goto Log;
                                            }
                                            else{ // Se nao escrevo para o usuario que a senha esta errada e repito o loop do while 
                                                printf("\nWrong password!\n");
                                                printf("\nTry again!\n");
                                                a = 0;
                                            }

                                        }while(a == 0);
                                    }
                                    else if (fun2 > 2){

                                        do{

                                            printf("\nNew password> "); 
                                            fgets(scf2[1], 50, stdin); 

                                            while (scf2[1][v_chp] != '\0'){
                                                if (scf2[1][v_chp] == '\n'){
                                                    scf2[1][v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (strlen(scf2[1]) < 8){
                                                printf("\nYour password has to have 8 characters!\n\n");
                                            }

                                        }while (strlen(scf2[1]) < 8);

                                        do{

                                            a = 1;
                                            printf("\nConfirm your new password: "); 
                                            fgets(senc, 50, stdin); 

                                            while (senc[v_chp] != '\0'){
                                                if (senc[v_chp] == '\n'){
                                                    senc[v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            // Comparo a senha do vetor senc (confirma senha) com o sc (vetor dos dados cadastrados)
                                            if (!strcmp(senc, scf2[1])){  // Se ambos forem iguais
                                                printf("\nNew password saved with success!\n"); // Falo que a nova senha foi salva                                                    printf("\nTry to login again!\n");
                                                goto Log;
                                            }
                                            else{ // Se nao escrevo para o usuario que a senha esta errada e repito o loop do while 
                                                printf("\nWrong password!\n");
                                                printf("\nTry again!\n");
                                                a = 0;
                                            }

                                        }while(a == 0);
                                    }
                                    else if (fun3 > 2){

                                        do{

                                            printf("\nNew password> "); 
                                            fgets(scf3[1], 50, stdin); 

                                            while (scf3[1][v_chp] != '\0'){
                                                if (scf3[1][v_chp] == '\n'){
                                                    scf3[1][v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (strlen(scf3[1]) < 8){
                                                printf("\nYour password has to have 8 characters!\n\n");
                                            }

                                        }while (strlen(scf3[1]) < 8);

                                        do{

                                            a = 1;
                                            printf("\nConfirm your new password: "); 
                                            fgets(senc, 50, stdin); 
                                            while (senc[v_chp] != '\0'){
                                                if (senc[v_chp] == '\n'){
                                                    senc[v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            // Comparo a senha do vetor senc (confirma senha) com o sc (vetor dos dados cadastrados)
                                            if (!strcmp(senc, scf3[1])){  // Se ambos forem iguais
                                                printf("\nNew password saved with success!\n"); // Falo que a nova senha foi salva
                                                printf("\nTry to login again!\n");
                                                goto Log;
                                            }
                                            else{ // Se nao escrevo para o usuario que a senha esta errada e repito o loop do while 
                                                printf("\nWrong password!\n");
                                                printf("\nTry again!\n");
                                                a = 0;
                                            }

                                        }while(a == 0);
                                    }
                                    else if (fun4 > 2){

                                        do{

                                            printf("\nNew password> "); 
                                            fgets(scf4[1], 50, stdin); 

                                            while (scf4[1][v_chp] != '\0'){
                                                if (scf4[1][v_chp] == '\n'){
                                                    scf4[1][v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (strlen(scf4[1]) < 8){
                                                printf("\nYour password has to have 8 characters!\n\n");
                                            }

                                        }while (strlen(scf4[1]) < 8);

                                        do{

                                            a = 1;
                                            printf("\nConfirm your new password: "); 
                                            fgets(senc, 50, stdin); 

                                            while (senc[v_chp] != '\0'){
                                                if (senc[v_chp] == '\n'){
                                                    senc[v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            // Comparo a senha do vetor senc (confirma senha) com o sc (vetor dos dados cadastrados)
                                            if (!strcmp(senc, scf4[1])){  // Se ambos forem iguais
                                                printf("\nNew password saved with success!\n"); // Falo que a nova senha foi salva
                                                printf("\nTry to login again!\n");
                                                goto Log;
                                            }
                                            else{ // Se nao escrevo para o usuario que a senha esta errada e repito o loop do while 
                                                printf("\nWrong password!\n");
                                                printf("\nTry again!\n");
                                                a = 0;
                                            }

                                        }while(a == 0);
                                    }
                                }
                                else {
                                    printf("\nOkay, you'll be sent to Login area!\n");
                                    goto Log;
                                }
                            }

                            //Caso a variavel de comparacao seja 0, ele enviara o usuario ja logado a Tela de menu
                            else if (cmp_fun == 0){
                                goto T_menu_Fun;
                            }

                            //Caso nenhuma das condições descritas anteriormente sejam satisfeitas o programa retornará para a tela de login
                            else{
                                printf("\nUser wasn't fond!\n");
                                goto Log;
                            }
                        }

                        //Voltando as opçoes inicias do login caso selecionado Funcionario, mas nao ouver registro o usuario sera enviado para a tela de cadastro
                        else if ((efoc == 'F' || efoc == 'f') && (arm_fun == 0)) {
                            printf("\nThere is no employee registered yet!\n");
                            printf("You'll be sent to employee's register area\n");
                            ret_Log++;  //Essa variavel indicara que apos feito o cadastro do funcionario devera retornar direto para o login
                            ret_lo_f++; //Essa por sua vez especifica que o retorno devera ser na opcao dos Funcionarios.
                            goto Reg_fun;
                            break;
                        }

                        //Daqui em diante e a mesma operação que foi utilizada par funcionarios mudando e claro algumas variaveis que sao especificas para a opcao cliente, mas a função e a mesma
                        if ((efoc == 'C' || efoc == 'c') && (arm_cli > 0)){

                            Log_c:

                            printf("\n  CLIENT'S LOGIN\n");

                            do{
                                do{
                                    printf("\nType your login:\n");
                                    printf("\nLogin> ");
                                    fgets(login, 50, stdin);  

                                    while (login[v_chp] != '\0'){
                                        if (login[v_chp] == '\n'){
                                            login[v_chp] = '\0';
                                        }
                                        v_chp++;
                                    }
                                    v_chp = 0;

                                    if (strlen(login) < 3){
                                        printf("\nYour login has to have more than 2 characters!\n");
                                    }

                                }while(strlen(login) < 3);

                                do{

                                    printf("Senha> ");
                                    fgets(senha, 50, stdin);  

                                    while (senha[v_chp] != '\0'){
                                        if (senha[v_chp] == '\n'){
                                            senha[v_chp] = '\0';
                                        }
                                        v_chp++;
                                    }
                                    v_chp = 0;

                                    if (strlen(senha) < 8){
                                        printf("\nYour password has to have more than 8 characters!\n");
                                    }

                                }while (strlen(senha) < 8);
                            
                                cmp_cli = 1;

                                for (m = 0; m <= cn; m++){

                                    if (m == 0){
                                        if (!strcmp(login, scc1[0]) && !strcmp(senha, scc1[1])){
                                            printf("\n   Welcome %s\n", login);
                                            cmp_cli = 0;
                                            break;
                                        }
                                        else if (!strcmp(login, scc1[0]) && strcmp(senha, scc1[1]) != 0){
                                            cli1++;
                                        }
                                    }
                                    else if (m == 1){
                                        if (!strcmp(login, scc2[0]) && !strcmp(senha, scc2[1])){
                                            printf("\n   Welcome %s\n", login);
                                            cmp_cli = 0;
                                            break;
                                        }
                                        else if (!strcmp(login, scc2[0]) && strcmp(senha, scc2[1]) != 0){
                                            cli2++;
                                        }
                                    }
                                    else if (m == 2){
                                        if (!strcmp(login, scc3[0]) && !strcmp(senha, scc3[1])){
                                            printf("\n   Welcome %s\n", login);
                                            cmp_cli = 0;
                                            break;
                                        }
                                        else if (!strcmp(login, scc3[0]) && strcmp(senha, scc3[1]) != 0){
                                            cli3++;
                                        }
                                    }
                                    
                                }
                                if (cmp_cli == 1 && (cli1 == 0 && cli2 == 0 && cli3 == 0)){  
                                    printf("\nUser wasn't fond. There is no user registered with this count!\n");
                                    tentlog++;  //É incrementado a variavel que conta as tentativas do usuario, sendo permitida apenas 3 tentativas
                                }
                                else{
                                    printf("\nWrong password!\n");
                                    tentlog++;
                                }

                            }while (cmp_cli == 1 && tentlog < 3);
                            
                            if (tentlog >= 2 && cmp_cli == 1 && (cli1 == 0 && cli2 == 0 && cli3 == 0)){
                                printf("\nYou had three chances to try log in, but your user's login wasn't find!\n");
                                if (cn < 2){
                                    rd = '\0';

                                    do{

                                        while (rd == '\n'){
                                            getchar();
                                        }

                                        printf("\nWould you like to go to register's area[Y/n]: ");
                                        scanf(" %c[^\n]", &rd);
                                        getchar();

                                    }while (rd != 'Y' && rd != 'y' && rd != 'N' && rd != 'n'); 

                                    if (rd == 'Y' || rd == 'y'){
                                        printf("\nOkay, you'll be sent to client's register area!\n");
                                        ret_Log++;
                                        ret_lo_c++;
                                        goto Reg_cli;
                                    }
                                    else{
                                        printf("\nOkay, Thank you!\n\n");
                                        goto T_inicio;
                                    }
                                    rd = '\0';
                                }

                                goto T_inicio;

                            }
                            else if (tentlog >= 2 && (cli1 > 2 || cli2 > 2 || cli3 > 2)){

                                a = 1;

                                do{ 
                                    while(alteraSen == '\n'){
                                        getchar();
                                    }

                                    printf("\nDo you intend to change your password[Y/n] ");
                                    scanf(" %c[^\n]", &alteraSen);
                                    getchar();

                                    if (alteraSen != 'Y' && alteraSen != 'y' && alteraSen != 'N' && alteraSen != 'n'){
                                        printf("\nInvalid option\n");
                                    }

                                }while(alteraSen != 'Y' && alteraSen != 'y' && alteraSen != 'N' && alteraSen != 'n');

                                if (alteraSen == 'Y' || alteraSen == 'y'){

                                    if (cli1 > 2){

                                        do{

                                            printf("\nNew password> "); 
                                            fgets(scc1[1], 50, stdin); 
                                            while (scc1[1][v_chp] != '\0'){
                                                if (scc1[1][v_chp] == '\n'){
                                                    scc1[1][v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (strlen(scc1[1]) < 8){
                                                printf("\nYour password has to have 8 characters!\n\n");
                                            }

                                        }while (strlen(scc1[1]) < 8);

                                        do{

                                            a = 1;
                                            printf("\nConfirm your new password: "); 
                                            fgets(senc, 50, stdin); 

                                            while (senc[v_chp] != '\0'){
                                                if (senc[v_chp] == '\n'){
                                                    senc[v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            // Comparo a senha do vetor senc (confirma senha) com o sc (vetor dos dados cadastrados)
                                            if (!strcmp(senc, scc1[1])){  // Se ambos forem iguais
                                                printf("\nNew password saved with success!\n"); // Falo que a nova senha foi salva
                                                printf("\nTry to login again!\n");
                                                goto Log;
                                            }
                                            else{ // Se nao escrevo para o usuario que a senha esta errada e repito o loop do while 
                                                printf("\nWrong password!\n");
                                                printf("\nTry again!\n");
                                                a = 0;
                                            }

                                        }while(a == 0);
                                    }
                                    else if (cli2 > 2){

                                        do{

                                            printf("\nNew password> "); 
                                            fgets(scc2[1], 50, stdin); 

                                            while (scc2[1][v_chp] != '\0'){
                                                if (scc2[1][v_chp] == '\n'){
                                                    scc2[1][v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (strlen(scc2[1]) < 8){
                                                printf("\nYour password has to have 8 characters!\n\n");
                                            }

                                        }while (strlen(scc2[1]) < 8);

                                        do{

                                            a = 1;
                                            printf("\nConfirm your new password: "); 
                                            fgets(senc, 50, stdin); 

                                            while (senc[v_chp] != '\0'){
                                                if (senc[v_chp] == '\n'){
                                                    senc[v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            // Comparo a senha do vetor senc (confirma senha) com o sc (vetor dos dados cadastrados)
                                            if (!strcmp(senc, scc2[1])){  // Se ambos forem iguais
                                                printf("\nNew password saved with success!\n"); // Falo que a nova senha foi salva                                                    printf("\nTry to login again!\n");
                                                goto Log;
                                            }
                                            else{ // Se nao escrevo para o usuario que a senha esta errada e repito o loop do while 
                                                printf("\nWrong password!\n");
                                                printf("\nTry again!\n");
                                                a = 0;
                                            }

                                        }while(a == 0);
                                    }
                                    else if (cli3 > 2){

                                        do{

                                            printf("\nNew password> "); 
                                            fgets(scc3[1], 50, stdin); 

                                            while (scc3[1][v_chp] != '\0'){
                                                if (scc3[1][v_chp] == '\n'){
                                                    scc3[1][v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (strlen(scc3[1]) < 8){
                                                printf("\nYour password has to have 8 characters!\n\n");
                                            }

                                        }while (strlen(scc3[1]) < 8);

                                        do{

                                            a = 1;
                                            printf("\nConfirm your new password: "); 
                                            fgets(senc, 50, stdin); 
                                            while (senc[v_chp] != '\0'){
                                                if (senc[v_chp] == '\n'){
                                                    senc[v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            // Comparo a senha do vetor senc (confirma senha) com o sc (vetor dos dados cadastrados)
                                            if (!strcmp(senc, scc3[1])){  // Se ambos forem iguais
                                                printf("\nNew password saved with success!\n"); // Falo que a nova senha foi salva
                                                printf("\nTry to login again!\n");
                                                goto Log;
                                            }
                                            else{ // Se nao escrevo para o usuario que a senha esta errada e repito o loop do while 
                                                printf("\nWrong password!\n");
                                                printf("\nTry again!\n");
                                                a = 0;
                                            }

                                        }while(a == 0);
                                    }
                                }
                                else {
                                    printf("\nOkay, you'll be sent to Login area!\n");
                                    goto Log;
                                }
                            }
                            else if (cmp_cli == 0){
                                goto T_menu_Cli;
                            }
                            else{
                                printf("\nUser wasn't fond!\n");
                                goto Log;
                            }
                        }
                        else if ((efoc == 'C' || efoc == 'c') && (arm_cli == 0)) {
                            printf("\nThere is no client registered yet!\n");
                            printf("You'll be sent to client's register area\n");
                            ret_Log++;
                            ret_lo_c++;
                            goto Reg_cli;
                            break;
                        }
                        else if (efoc != 'F' && efoc != 'f' && efoc != 'C' && efoc != 'c'){
                            printf("\n+-\n");
                            a = 0;
                        }

                    }while (a == 0);
                }

                //Voltando ao inicio do login caso nao haja nenhum registro nem de funcionario nem de cliente ele te enviara a tela de cadastro que apos finalizada te tará de volta direto para a tela de login.
                else{
                    printf("\nThere is no one registered yet, I'll send you to Sign up!\n\n");
                    ret_Log++;
                    goto Reg;
                }

            break;

            case '2':

                //Endereço para ciclo das telas e funcionamento do programa
                Reg:
                
                printf("\n  Welcome, you chose the option - Sign up\n"); 

                //Loop para caso o usuario digite algo diferente do que foi solicitado
                do{

                    //As variaveis abaixo são zeradas para o funcionamento do loop
                    a = 1;
                    efoc = '\0';

                    while(efoc == '\n'){
                        getchar();
                    }

                    //Aqui sao dadas as opçoes de cadastro para o usuario
                    printf("\nYou can register an employee or a client.\n");
                    printf("\n   'F' - employee\n\n   'C' - client\n\n");
                    printf("What do you want to register: ");   //Peço ao cliente o qual das duas opcoes ele ira quere cadastrar
                    scanf(" %c[^\n]", &efoc);
                    getchar();

                    //As opcoes foram separa utilizando switch case
                    switch (efoc){
                        case 'f': case 'F':
                            nc = 4; //caso seja selecionada funcionario indico que pode cadastrar ate 4 pessoas como funcionario
                            printf("\n\nYou can register %d employee.\n", nc - (cont_fun + 1));
                        break;

                        case 'c': case 'C':
                            nc = 3; //caso seja selecionada cliente indico que pode cadastrar ate 4 pessoas como cliente
                            printf("\n\nYou can register %d clients.\n", nc - (cont_cli + 1));
                        break;

                        default:
                            printf("\nError! You must write a letter F or C!\n");   //Caso o usuario digite algo diferente de F ou C, mostra na tela que ele deve digitar F ou c e permanece no loop
                            a = 0;
                    }
                }while(a == 0);

                //Loop para repetir os comandos do codigo abaixo caso o usuario queira cadastrar mais de uma pessoa (FUNCIONARIO / CLIENTE).
                do{

                    //Caso o numero maximo de cadastro seja 3 o codigo abaixo e executado, subentendendo que se trata de um registro para clientes
                    if (nc == 3){

                        //Endereço para a funcao 'goto' para os casos mostrados e comentados no login
                        Reg_cli:

                        //Caso a variavel que indique para voltar para tela de login seja maior que 0 ele informa a quantidade maxima de pessoas que podem ser cadastradas
                        if (ret_Log > 0){
                            nc = 3; //Aqui é informado novamente o numero max pois o recurso da funcao 'goto' ignora o que esta acima dela sendo necessario reinformar ao codigo esse valor
                        }

                        //Faz se a contagem do numero de pessoas registradas (salva os dados nas matrizes que são identificadas pela variavel cn/CLIENTES)
                        for(cn = cont_cli; cn < nc; cn++){

                            printf("\n\tREGISTER CLIENTS\n");

                            //Primeiro cliente
                            if (cn == 0){

                                //Serve para endereçar o login para um lugar na matriz e a senha para outro separando ambos
                                for (n = 0; n < 2; n++){

                                    if (n == 0){ //Endereca os dados de login digitados para o primeiro endereco vetor de sc

                                        /*
                                            Nessa parte teremos o mesmo padrao de login maior que 2 carateres
                                            Senha maior que 8 caracteres, porem compararemos o login CLIENTE
                                            digitado com os logins FUNCIONARIO se ouver algum salvo.
                                        */

                                        //Loop para verificar se o login digitado e diferente dos logins Funcionario ou logins Cliente 
                                        do{
                                            printf("\nPlease type your login user:\n\n"); 
                                            printf("Login> "); 
                                            fgets(scc1[n], 50, stdin); // Atribui o que foi digitado pelo usuario para o vetor sc

                                            while (scc1[n][v_chp] != '\0'){
                                    
                                                if (scc1[n][v_chp] == '\n'){
                                                    scc1[n][v_chp] = '\0';
                                                }   
                                                v_chp++; 
                                            }
                                            v_chp = 0;

                                            if (strlen(scc1[n]) < 3){
                                                printf("\nYour login has to have more than 2 characters!\n");
                                            }

                                            cmp_fun = 1;

                                            //Apartir desse ponto o que se difere do login e que agora ele compara o login digitado com os logins salvos no registro dos Funcionarios
                                            for(m = 0; m <= fn; m++){

                                                if (m == 0){
                                                    if (!strcmp(scc1[n], scf1[m])){
                                                        printf("\nYour login is the same login of employee's user %d", m + 1);
                                                        cmp_fun = 0;
                                                        break;
                                                    }
                                                }
                                                else if (m == 1){
                                                    if (!strcmp(scc1[n], scf2[n])){
                                                        printf("\nYour login is the same login of employee's user %d", m + 1);
                                                        cmp_fun = 0;
                                                        break;
                                                    }
                                                }
                                                else if (m == 2){
                                                    if (!strcmp(scc1[n], scf3[n])){
                                                        printf("\nYour login is the same login of employee's user %d", m + 1);
                                                        cmp_fun = 0;
                                                        break;
                                                    }
                                                }
                                                else{
                                                    if (!strcmp(scc1[n], scf4[n])){
                                                        printf("\nYour login is the same login of employee's user %d", m + 1);
                                                        cmp_fun = 0;
                                                        break;
                                                    }
                                                }
                                            }

                                        }while ((strlen(scc1[n]) < 3) || (cmp_fun == 0));
                                    }

                                    //Endereço para a senha
                                    else{

                                        do{

                                            printf("Senha> "); 
                                            fgets(scc1[n], 50, stdin); 

                                            while (scc1[n][v_chp] != '\0'){
                                                if (scc1[n][v_chp] == '\n'){
                                                    scc1[n][v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (strlen(scc1[n]) < 8){
                                                printf("\nYour password has to have 8 characters!\n\n");
                                            }

                                        }while (strlen(scc1[n]) < 8);

                                        // Loop para confirmacao da senha do usuario 
                                        do{

                                            a = 1;
                                            printf("\nConfirm your password: "); 
                                            fgets(senc, 50, stdin); 

                                            while (senc[v_chp] != '\0'){
                                                    if (senc[v_chp] == '\n'){
                                                        senc[v_chp] = '\0';
                                                    }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            // Comparo a senha do vetor senc (confirma senha) com o sc (vetor dos dados cadastrados)
                                            if (!strcmp(senc, scc1[n])){  // Se ambos forem iguais
                                                printf("\nUser and password saved with success!\n"); // Falo que o usuario e senha foram salvos
                                                arm_cli++;
                                            }
                                            else{ // Se nao escrevo para o usuario que a senha esta errado e repito o loop do while 
                                                printf("\nWrong password!\n");
                                                printf("\nTry again!\n");
                                                a = 0;
                                            }

                                        }while(a == 0);
                                    }
                                }

                                //Loop para verificar se o usuario digitou o que foi solicitado dentro das opçoes
                                do{

                                    while(rd == '\n'){
                                        getchar();
                                    }

                                    printf("\nDo you want to register one more client[Y/n]: ");
                                    scanf(" %c[^\n]", &rd);
                                    getchar();

                                    if ((rd != 'Y' && rd != 'y') && (rd != 'N' && rd != 'n')){
                                        printf("\nError! You must type the letter Y or n!\n");
                                    }

                                }while((rd != 'Y' && rd != 'y') && (rd != 'N' && rd != 'n'));

                                if (rd == 'Y' || rd == 'y'){
                                    printf("\nOkay\n");
                                }

                                else if (rd == 'N' || rd == 'n'){
                                    printf("\nOkay, Thank you!\n");
                                    break;
                                }
                            }

                            /*
                                A partir do sengundo Cliente o login diferentemente do primeiro
                                sera comparado se é ou não igual ao login CLIENTE alem do login FUNCIONARIO!!!
                            */

                            else if (cn == 1){

                                for (n = 0; n < 2; n++){

                                    if (n == 0){ 

                                        do{

                                            printf("\nPlease type your login user:\n\n"); 
                                            printf("Login> "); 
                                            fgets(scc2[n], 50, stdin); 
                            
                                            while (scc2[n][v_chp] != '\0'){
                                                if (scc2[n][v_chp] == '\n'){
                                                    scc2[n][v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;
            
                                            if (strlen(scc2[n]) < 3){
                                                printf("\nYour login has to have more than 2 characters!\n");
                                            }

                                            //Por ter que verificar tanto login funcionario quanto login cliente estas variaveis agora farão parte do codigo
                                            cmp_fun = 1;    
                                            cmp_cli = 1;

                                            for (m = 0; m <= fn; m++){

                                                if (m == 0){
                                                    if (!strcmp(scc2[n], scf1[m])){
                                                        printf("\nYour login is the same login of employee's user %d", m + 1);
                                                        cmp_fun = 0;
                                                        break;
                                                    }
                                                }
                                                else if (m == 1){
                                                    if (!strcmp(scc2[n], scf2[n])){
                                                        printf("\nYour login is the same login of employee's user %d", m + 1);
                                                        cmp_fun = 0;
                                                        break;
                                                    }
                                                }
                                                else if (m == 2){
                                                    if (!strcmp(scc2[n], scf3[n])){
                                                        printf("\nYour login is the same login of employee's user %d", m + 1);
                                                        cmp_fun = 0;
                                                        break;
                                                    }
                                                }
                                                else{
                                                    if (!strcmp(scc2[n], scf4[n])){
                                                        printf("\nYour login is the same login of employee's user %d", m + 1);
                                                        cmp_fun = 0;
                                                        break;
                                                    }
                                                }
                                            }

                                            //Aqui faço a comparaçao com o login usuario do cliente anterior
                                            for (m = 0; m < cn; m++){
                                                if (!strcmp(scc2[n], scc1[m])){
                                                    printf("\nYour login is the same login of client's user %d", m + 1);
                                                    cmp_cli = 0;
                                                }
                                            }

                                        }while ((strlen(scc2[n]) < 3) || (cmp_fun == 0) || (cmp_cli == 0));
                                    }
                                    else{ //Endereca os dados de senha digitados para o segundo endereco do vetor sc

                                        do{
                                            printf("Senha> "); 
                                            fgets(scc2[n], 50, stdin); 

                                            while (scc2[n][v_chp] != '\0'){
                                                if (scc2[n][v_chp] == '\n'){
                                                    scc2[n][v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (strlen(scc2[n]) < 8){
                                                printf("\nYour password has to have 8 characters!\n\n");
                                            }

                                        }while (strlen(scc2[n]) < 8);

                                        do{

                                            a = 1;
                                            printf("\nConfirm your password: "); 
                                            fgets(senc, 50, stdin); 

                                            while (senc[v_chp] != '\0'){
                                                    if (senc[v_chp] == '\n'){
                                                        senc[v_chp] = '\0';
                                                    }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (!strcmp(senc, scc2[n])){  
                                                printf("\nUser and password saved with success!\n"); 
                                            }
                                            else{ 
                                                printf("\nWrong password!\n");
                                                printf("\nTry again!\n");
                                                a = 0;
                                    
                                            }

                                        }while(a == 0);
                                    }   
                                }
                                do{

                                    while(rd == '\n'){
                                        getchar();
                                    }

                                    printf("\nDo you want to register one more client[Y/n]: ");
                                    scanf(" %c[^\n]", &rd);
                                    getchar();

                                    if ((rd != 'Y' && rd != 'y') && (rd != 'N' && rd != 'n')){
                                        printf("\nError! You must type the letter Y or n!\n");
                                    }

                                }while((rd != 'Y' && rd != 'y') && (rd != 'N' && rd != 'n'));

                                if (rd == 'Y' || rd == 'y'){
                                    printf("\nOkay\n");
                                }
                                else if (rd == 'N' || rd == 'n'){
                                    printf("\nOkay, Thank you\n");
                                    break;
                                }
                            }
                            else if (cn == 2){

                                for (n = 0; n < 2; n++){

                                    if (n == 0){ 

                                        do{

                                            printf("\nPlease type your login user:\n\n"); 
                                            printf("Login> "); 
                                            fgets(scc3[n], 50, stdin); 
                            
                                            while (scc3[n][v_chp] != '\0'){
                                                if (scc3[n][v_chp] == '\n'){
                                                    scc3[n][v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (strlen(scc3[n]) < 3){
                                                printf("\nYour login has to have more than 2 characters!\n");
                                            }

                                            cmp_fun = 1;
                                            cmp_cli = 1;

                                            for (m = 0; m <= fn; m++){

                                                if (m == 0){
                                                    if (!strcmp(scc3[n], scf1[m])){
                                                        printf("\nYour login is the same login of employee's user %d", m + 1);
                                                        cmp_fun = 0;
                                                        break;
                                                    }
                                                }
                                                else if (m == 1){
                                                    if (!strcmp(scc3[n], scf2[n])){
                                                        printf("\nYour login is the same login of employee's user %d", m + 1);
                                                        cmp_fun = 0;
                                                        break;
                                                    }
                                                }
                                                else if (m == 2){
                                                    if (!strcmp(scc3[n], scf3[n])){
                                                        printf("\nYour login is the same login of employee's user %d", m + 1);
                                                        cmp_fun = 0;
                                                        break;
                                                    }
                                                }
                                                else{
                                                    if (!strcmp(scc3[n], scf4[n])){
                                                        printf("\nYour login is the same login of employee's user %d", m + 1);
                                                        cmp_fun = 0;
                                                        break;
                                                    }
                                                }
                                            }

                                            for (m = 0; m < cn; m++){

                                                if (m == 0){
                                                    if (!strcmp(scc3[n], scc1[m])){
                                                        printf("\nYour login is the same login of client's user %d", m + 1);
                                                        cmp_cli = 0;
                                                        break;
                                                    }
                                                }
                                                else{
                                                    if (!strcmp(scc3[n], scc2[n])){
                                                        printf("\nYour login is the same login of client's user %d", m + 1);
                                                        cmp_cli = 0;
                                                        break;
                                                    }
                                                }
                                            }

                                        }while ((strlen(scc3[n]) < 3) || (cmp_fun == 0) || (cmp_cli == 0));
                                    }
                                    else{ 

                                        do{

                                            printf("Senha> "); // Peco para inserir a senha
                                            fgets(scc3[n], 50, stdin); // Atribui o que foi digitado pelo usuario para o vetor sc

                                            while (scc3[n][v_chp] != '\0'){
                                                if (scc3[n][v_chp] == '\n'){
                                                    scc3[n][v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (strlen(scc3[n]) < 8){
                                                printf("\nYour password has to have 8 characters!\n\n");
                                            }

                                        }while (strlen(scc3[n]) < 8);
                            
                            

                                        do{

                                            a = 1;
                                            printf("\nConfirm your password: "); 
                                            fgets(senc, 50, stdin); 

                                            while (senc[v_chp] != '\0'){
                                                    if (senc[v_chp] == '\n'){
                                                        senc[v_chp] = '\0';
                                                    }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (!strcmp(senc, scc3[n])){ 
                                                printf("\nUser and password saved with success!\n"); 
                                            }
                                            else{  
                                                printf("\nWrong password!\n");
                                                printf("\nTry again!\n\n");
                                                a = 0;
                                            }

                                        }while(a == 0);
                                    }
                                }

                                printf("\nYou reached the maximum capacity of register for clients.\n");
                                break;

                            }
                        }

                        //Aqui faço a logica para que as matrizes siguam uma ordem e que uma vez salvas nao sejam reescritas
                        //Esse if e else sao necessario tanto para a quantidades de clientes registrados tanto para o contre das matrizes utilizadas
                        if (cn < 2){
                            cont_cli = cn + 1;
                            printf("\nYou registered %d clients\n", cont_cli);
                        }
                        else{
                            cont_cli = cn;
                            printf("\nYou registered %d clients\n", cont_cli + 1);
                        }

                    }
                    else{

                        /*
                            Agora chegemos na area de registro de funcionarios, esse por sua vez tera
                            as mesmas funcionalidades mostradas e explicadas da are de registro de cliente
                            então não comentarei tantas linhas, o que sera diferente serao as variaveis 
                            especificas para organizar e controlar os registros de FUNCIONARIOS.
                        */

                        Reg_fun:

                        if (ret_Log > 0){
                            nc = 4;
                        }

                        for (fn = cont_fun; fn < nc; fn++){

                            printf("\n\tREGISTER EMPLOYEES\n");

                            if (fn == 0){

                                for (n = 0; n < 2; n++){

                                    if (n == 0){ 

                                        do{

                                            printf("\nPlease type your login user:\n\n"); 
                                            printf("Login> "); 
                                            fgets(scf1[n], 50, stdin);
                            
                                            while (scf1[n][v_chp] != '\0'){
                                                if (scf1[n][v_chp] == '\n'){
                                                    scf1[n][v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (strlen(scf1[n]) < 3){
                                                printf("\nYour login has to have more than 2 characters!\n");
                                            }

                                            cmp_cli = 1;

                                            for (m = 0; m <= cn; m++){

                                                if (m == 0){
                                                    if (!strcmp(scf1[n], scc1[m])){
                                                        printf("\nYour login is the same login of client's user %d", m + 1);
                                                        cmp_cli = 0;
                                                        break;
                                                    }
                                                }
                                                else if (m == 1){
                                                    if (!strcmp(scf1[n], scc2[n])){
                                                        printf("\nYour login is the same login of client's user %d", m + 1);
                                                        cmp_cli = 0;
                                                        break;
                                                    }
                                                }
                                                else if (m == 2){
                                                    if (!strcmp(scf1[n], scc3[n])){
                                                        printf("\nYour login is the same login of client's user %d", m + 1);
                                                        cmp_cli = 0;
                                                        break;
                                                    }
                                                }
                                            }            

                                        }while ((strlen(scf1[n]) < 3) || (cmp_cli == 0));
                                    }
                                    else{ 

                                        do{

                                            printf("Senha> "); 
                                            fgets(scf1[n], 50, stdin); 
            
                                            while (scf1[n][v_chp] != '\0'){
                                                if (scf1[n][v_chp] == '\n'){
                                                    scf1[n][v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (strlen(scf1[n]) < 8){
                                                printf("\nYour password has to have 8 characters!\n\n");
                                            }

                                        }while (strlen(scf1[n]) < 8);

                                        do{

                                            a = 1;
                                            printf("\nConfirm your password: "); 
                                            fgets(senc, 50, stdin); 

                                            while (senc[v_chp] != '\0'){
                                                    if (senc[v_chp] == '\n'){
                                                        senc[v_chp] = '\0';
                                                    }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (!strcmp(senc, scf1[n])){  
                                                printf("\nUser and password saved with success!\n"); 
                                                arm_fun++;
                                            }
                                            else{ 
                                                printf("\nWrong password!\n");
                                                printf("\nTry again!\n");
                                                a = 0;
                                            }

                                        }while(a == 0);
                                    }
                                }

                                do{

                                    while(rd == '\n'){
                                        getchar();
                                    }

                                    printf("\nDo you want to register one more employee[Y/n]: ");
                                    scanf(" %c[^\n]", &rd);
                                    getchar();

                                    if ((rd != 'Y' && rd != 'y') && (rd != 'N' && rd != 'n')){
                                        printf("\nError! You must type the letter Y or n!\n");
                                    }

                                }while((rd != 'Y' && rd != 'y') && (rd != 'N' && rd != 'n'));

                                if (rd == 'Y' || rd == 'y'){
                                    printf("\nOkay\n");
                                }
                                else if (rd == 'N' || rd == 'n'){
                                    printf("\nOkay, Thank you\n");
                                    break;
                                }
                            }
                            else if (fn == 1){

                                for (n = 0; n < 2; n++){

                                    if (n == 0){

                                        do{

                                            printf("\nPlease type your login user:\n\n");
                                            printf("Login> ");
                                            fgets(scf2[n], 50, stdin);
                            
                                            while (scf2[n][v_chp] != '\0'){
                                                if (scf2[n][v_chp] == '\n'){
                                                    scf2[n][v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (strlen(scf2[n]) < 3){
                                                printf("\nYour login has to have more than 2 characters!\n");
                                            }

                                            cmp_cli = 1;
                                            cmp_fun = 1;

                                            for (m = 0; m <= cn; m++){

                                                if (m == 0){
                                                    if (!strcmp(scf2[n], scc1[m])){
                                                        printf("\nYour login is the same login of client's user %d", m + 1);
                                                        cmp_cli = 0;
                                                        break;
                                                    }
                                                }
                                                else if (m == 1){
                                                    if (!strcmp(scf2[n], scc2[n])){
                                                        printf("\nYour login is the same login of client's user %d", m + 1);
                                                        cmp_cli = 0;
                                                        break;
                                                    }
                                                }
                                                else{
                                                    if (!strcmp(scf2[n], scc3[n])){
                                                        printf("\nYour login is the same login of client's user %d", m + 1);
                                                        cmp_cli = 0;
                                                        break;
                                                    }
                                                }
                                            }

                                            for (m = 0; m < fn; m++){

                                                if (!strcmp(scf2[n], scf1[m])){
                                                    printf("\nYour login is the same login of employee's user %d", m + 1);
                                                    cmp_fun = 0;
                                                }
                                            }

                                        }while ((strlen(scf2[n]) < 3) || (cmp_cli == 0) || (cmp_fun == 0));
                                    }
                                    else{ 

                                        do{

                                            printf("Senha> "); 
                                            fgets(scf2[n], 50, stdin);

                                            while (scf2[n][v_chp] != '\0'){
                                                if (scf2[n][v_chp] == '\n'){
                                                    scf2[n][v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (strlen(scf2[n]) < 8){
                                                printf("\nYour password has to have 8 characters!\n\n");
                                            }

                                        }while (strlen(scf2[n]) < 8);

                                        do{

                                            a = 1;
                                            printf("\nConfirm your password: "); 
                                            fgets(senc, 50, stdin); 

                                            while (senc[v_chp] != '\0'){
                                                    if (senc[v_chp] == '\n'){
                                                        senc[v_chp] = '\0';
                                                    }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (!strcmp(senc, scf2[n])){  
                                                printf("\nUser and password saved with success!\n");
                                            }
                                            else{
                                                printf("\nWrong password!\n");
                                                printf("\nTry again!\n");
                                                a = 0;
                                            }

                                        }while(a == 0);
                                    }
                                }

                                do{

                                    while(rd == '\n'){
                                        getchar();
                                    }

                                    printf("\nDo you want to register one more employee[Y/n]: ");
                                    scanf(" %c[^\n]", &rd);
                                    getchar();

                                    if ((rd != 'Y' && rd != 'y') && (rd != 'N' && rd != 'n')){
                                        printf("\nError! You must type the letter Y or n!\n");
                                    }

                                }while((rd != 'Y' && rd != 'y') && (rd != 'N' && rd != 'n'));

                                if (rd == 'Y' || rd == 'y'){
                                    printf("\nOkay\n");
                                }
                                else if (rd == 'N' || rd == 'n'){
                                    printf("\nOkay, Thank you\n");
                                    break;
                                }
                            }
                            else if (fn == 2){

                                for (n = 0; n < 2; n++){

                                    if (n == 0){ 

                                        do{

                                            printf("\nPlease type your login user:\n\n"); 
                                            printf("Login> ");
                                            fgets(scf3[n], 50, stdin); 
                            
                                            while (scf3[n][v_chp] != '\0'){
                                                if (scf3[n][v_chp] == '\n'){
                                                    scf3[n][v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (strlen(scf3[n]) < 3){
                                                printf("\nYour login has to have more than 2 characters!\n");
                                            }

                                            cmp_cli = 1;
                                            cmp_fun = 1;

                                            for (m = 0; m <= cn; m++){

                                                if (m == 0){
                                                    if (!strcmp(scf3[n], scc1[m])){
                                                        printf("\nYour login is the same login of client's user %d", m + 1);
                                                        cmp_cli = 0;
                                                        break;
                                                    }
                                                }
                                                else if (m == 1){
                                                    if (!strcmp(scf3[n], scc2[n])){
                                                        printf("\nYour login is the same login of client's user %d", m + 1);
                                                        cmp_cli = 0;
                                                        break;
                                                    }
                                                }
                                                else{
                                                    if (!strcmp(scf3[n], scc3[n])){
                                                        printf("\nYour login is the same login of client's user %d", m + 1);
                                                        cmp_cli = 0;
                                                        break;
                                                    }
                                                }
                                            }

                                            for (m = 0; m < fn; m++){

                                                if (m == 0){
                                                    if (!strcmp(scf3[n], scf1[m])){
                                                        printf("\nYour login is the same login of employee's user %d", m + 1);
                                                        cmp_fun = 0;
                                                        break;
                                                    }
                                                }
                                                else if (m == 1){
                                                    if (!strcmp(scf3[n], scf2[n])){
                                                        printf("\nYour login is the same login of employee's user %d", m + 1);
                                                        cmp_fun = 0;
                                                        break;
                                                    }
                                                }
                                            }

                                        }while ((strlen(scf3[n]) < 3) || (cmp_cli == 0) || (cmp_fun == 0));
                                    }
                                    else{ 

                                        do{

                                            printf("Senha> "); 
                                            fgets(scf3[n], 50, stdin); 

                                            while (scf3[n][v_chp] != '\0'){
                                                if (scf3[n][v_chp] == '\n'){
                                                    scf3[n][v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (strlen(scf3[n]) < 8){
                                                printf("\nYour password has to have 8 characters!\n\n");
                                            }

                                        }while (strlen(scf3[n]) < 8);

                                        do{

                                            a = 1;
                                            printf("\nConfirm your password: "); 
                                            fgets(senc, 50, stdin); 

                                            while (senc[v_chp] != '\0'){
                                                    if (senc[v_chp] == '\n'){
                                                        senc[v_chp] = '\0';
                                                    }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (!strcmp(senc, scf3[n])){
                                                printf("\nUser and password saved with success!\n");
                                            }
                                            else{
                                                printf("\nWrong password!\n");
                                                printf("\nTry again!\n");
                                                a = 0;
                                            }

                                        }while(a == 0);
                                    }
                                }

                                do{

                                    while(rd == '\n'){
                                        getchar();
                                    }

                                    printf("\nDo you want to register one more employee[Y/n]: ");
                                    scanf(" %c[^\n]", &rd);
                                    getchar();

                                    if ((rd != 'Y' && rd != 'y') && (rd != 'N' && rd != 'n')){
                                        printf("\nError! You must type the letter Y or n!\n");            
                                    }

                                }while((rd != 'Y' && rd != 'y') && (rd != 'N' && rd != 'n'));

                                if (rd == 'Y' || rd == 'y'){
                                    printf("\nOkay\n");
                                }
                                else if (rd == 'N' || rd == 'n'){
                                    printf("\nOkay, Thank you\n");
                                    break;
                                }
                            }
                            else if (fn == 3){

                                for (n = 0; n < 2; n++){

                                    if (n == 0){

                                        do{

                                            printf("\nPlease type your login user:\n\n"); 
                                            printf("Login> "); 
                                            fgets(scf4[n], 50, stdin);
                            
                                            while (scf4[n][v_chp] != '\0'){
                                                if (scf4[n][v_chp] == '\n'){
                                                    scf4[n][v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (strlen(scf4[n]) < 3){
                                                printf("\nYour login has to have more than 2 characters!\n");
                                            }

                                            cmp_cli = 1;
                                            cmp_fun = 1;

                                            for (m = 0; m <= cn; m++){

                                                if (m == 0){
                                                    if (!strcmp(scf4[n], scc1[m])){
                                                        printf("\nYour login is the same login of client's user %d", m + 1);
                                                        cmp_cli = 0;
                                                        break;
                                                    }
                                                }
                                                else if (m == 1){
                                                    if (!strcmp(scf4[n], scc2[n])){
                                                        printf("\nYour login is the same login of client's user %d", m + 1);
                                                        cmp_cli = 0;
                                                        break;
                                                    }
                                                }
                                                else if (m == 2){
                                                    if (!strcmp(scf4[n], scc3[n])){
                                                        printf("\nYour login is the same login of client's user %d", m + 1);
                                                        cmp_cli = 0;
                                                        break;
                                                    }
                                                }
                                            }

                                            for (m = 0; m < fn; m++){

                                                if (m == 0){
                                                    if (!strcmp(scf4[n], scf1[m])){
                                                        printf("\nYour login is the same login of employee's user %d", m + 1);
                                                        cmp_fun = 0;
                                                        break;
                                                    }
                                                }
                                                else if (m == 1){
                                                    if (!strcmp(scf4[n], scf2[n])){
                                                        printf("\nYour login is the same login of employee's user %d", m + 1);
                                                        cmp_fun = 0;
                                                        break;
                                                    }
                                                }
                                                else if (m == 2){
                                                    if (!strcmp(scf4[n], scf3[n])){
                                                        printf("\nYour login is the same login of employee's user %d", m + 1);
                                                        cmp_fun = 0;
                                                        break;
                                                    }
                                                }
                                            }

                                        }while ((strlen(scf4[n]) < 3) || (cmp_cli == 0) || (cmp_fun == 0));
                                    }
                                    else{ 

                                        do{

                                            printf("Senha> "); 
                                            fgets(scf4[n], 50, stdin); 

                                            while (scf4[n][v_chp] != '\0'){
                                                if (scf4[n][v_chp] == '\n'){
                                                    scf4[n][v_chp] = '\0';
                                                }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (strlen(scf4[n]) < 8){
                                                printf("\nYour password has to have 8 characters!\n\n");
                                            }

                                        }while (strlen(scf4[n]) < 8);

                                        do{

                                            a = 1;
                                            printf("Confirm your password: "); 
                                            fgets(senc, 50, stdin); 

                                            while (senc[v_chp] != '\0'){
                                                    if (senc[v_chp] == '\n'){
                                                        senc[v_chp] = '\0';
                                                    }
                                                v_chp++;
                                            }
                                            v_chp = 0;

                                            if (!strcmp(senc, scf4[n])){  
                                                printf("\nUser and password saved with success!\n"); 
                                            }
                                            else{  
                                                printf("\nWrong password!\n");
                                                printf("\nTry again!\n");
                                                a = 0;
                                            }

                                        }while(a == 0);
                                    }
                                }

                                printf("\nYou reached the maximum capacity of register for employees.\n");
                                break;

                            }
                        }

                        if (fn < 3){
                            cont_fun = fn + 1;
                            printf("\nYou registered %d employees\n", cont_fun);
                        }
                        else{
                            cont_fun = fn;
                            printf("\nYou registered %d employees\n", nc);
                        }
                    }

                    /*
                        Apos toda a fase do cadastro eu mostro na tela quantos usuarios login de
                        FUNCIONARIO e/ou CLIENTE eu cadastrei para isso utilizo do mesmo mecanismo
                        para comparação de logins e endereçamento de senha e login para cada uma das 
                        matrizes.
                    */

                    if (nc == 3){

                        for (m = 0; m <= cn; m++){
                
                            if (m == 0){
                                for (n = 0; n < 2; n++){
                                    if (n == 0){
                                        printf("\nClient's user number %d\n\n", m + 1);
                                        printf("Login> ");
                                        printf("%s\n", scc1[n]);
                                    }
                                    else{
                                        printf("Senha> ");
                                        printf("%s\n", scc1[n]);
                                    }
                                }
                            }
                            else if (m == 1){
                                for (n = 0; n < 2; n++){
                                    if (n == 0){
                                        printf("\nClient's user number %d\n\n", m + 1);
                                        printf("Login> ");
                                        printf("%s\n", scc2[n]);
                                    }
                                    else{
                                        printf("Senha> ");
                                        printf("%s\n", scc2[n]);
                                    }
                                }
                            }
                            else if (m == 2){
                                for (n = 0; n < 2; n++){
                                    if (n == 0){
                                        printf("\nClient's user number %d\n\n", m + 1);
                                        printf("Login> ");
                                        printf("%s\n", scc3[n]);
                                    }
                                    else{
                                        printf("Senha> ");
                                        printf("%s\n", scc3[n]);
                                    }
                                }
                            }
                            else{
                                printf("\nThere's something wrong!\n");
                                break;
                            }
                        }
                    }
                    else{

                        for (m = 0; m <= fn; m++){
            
                            if (m == 0){
                                for (n = 0; n < 2; n++){
                                    if (n == 0){
                                        printf("\nEmployee's user number %d\n\n", m + 1);
                                        printf("Login> ");
                                        printf("%s\n", scf1[n]);
                                    }
                                    else{
                                        printf("Senha> ");
                                        printf("%s\n", scf1[n]);
                                    }
                                }
                            }
                            else if (m == 1){
                                for (n = 0; n < 2; n++){
                                    if (n == 0){
                                        printf("\nEmployee's user number %d\n\n", m + 1);
                                        printf("Login> ");
                                        printf("%s\n", scf2[n]);
                                    }
                                    else{
                                        printf("Senha> ");
                                        printf("%s\n", scf2[n]);
                                    }
                                }
                            }
                            else if (m == 2 ){
                                for (n = 0; n < 2; n++){
                                    if (n == 0){
                                        printf("\nEmployee's user number %d\n\n", m + 1);
                                        printf("Login> ");
                                        printf("%s\n", scf3[n]);
                                    }
                                    else{
                                        printf("Senha> ");
                                        printf("%s\n", scf3[n]);
                                    }
                                }
                            }
                            else if (m == 3){
                                for (n = 0; n < 2; n++){
                                    if (n == 0){
                                        printf("\nEmployee's user number %d\n\n", m + 1);
                                        printf("Login> ");
                                        printf("%s\n", scf4[n]);
                                    }
                                    else{
                                        printf("Senha> ");
                                        printf("%s\n", scf4[n]);
                                    }
                                }
                            }
                            else{
                                printf("\nThere's something wrong!\n");
                            }
                        }
                    }

                    //Essa verificação é para que o loop seja feito sem ocorrência de bugs
                    if (cad == 'Y' || cad == 'y'){
                        cad = '\0';
                    }

                    /*
                        Na estrutura abaixo se verifica a opcao escolhida pelo usuario (CLIENTE / FUNCIONARIO)
                        se caso for CLIENTE ele verificará se há matrizes disponives para armazenamento de
                        FUNCIONARIOS e se Caso o programa nao pedir para retornar para a 
                        tela login (Recurso comentado na tela de login).
                        Se caso todos os requisitos forem cumpridos ele perguntara se o usuario deseja fazer um
                        cadastro de um FUNCIONARIO (se caso a primeira escolha for CLIENTE), ou vice-versa.
                    */

                    if ((efoc == 'C' || efoc == 'c') && (fn < 3) && (ret_lo_c == 0)){

                        if((cn - 1) < nc){

                            do{

                                while (cad == '\n'){
                                    getchar();
                                }

                                printf("\nDo you pretend to register a EMPLOYEE[Y/n]? ");
                                scanf(" %c[^\n]", &cad);
                                getchar();

                                if ((cad != 'Y' && cad != 'y') && (cad != 'N' && cad != 'n')){
                                    printf("\nError! You must type the letter Y or n!\n");
                                }

                            }while((cad != 'Y' && cad != 'y') && (cad != 'N' && cad != 'n'));

                            if (cad == 'Y' || cad == 'y'){

                                printf("\nOkay\n");
                                nc = 4;
                                efoc = '\0';
                            }
                            else if (cad == 'N' || cad == 'n'){

                                printf("\nOkay, thank you for your presence!\n");
                                break;
                            }
                        }
                    }
        
                    else if((efoc == 'F' || efoc == 'f') && (cn < 2) && (ret_lo_f == 0)){

                        if((fn - 1) < nc){

                            do{

                                while (cad == '\n'){
                                    getchar();
                                }

                                printf("\nDo you pretend to register a CLIENT[Y/n]? ");
                                scanf(" %c[^\n]", &cad);
                                getchar();

                                if (cad != 'Y' && cad != 'y' && cad != 'N' && cad != 'n'){
                                    printf("\nError! You must type the letter Y or n!\n");
                                }

                            }while((cad != 'Y' && cad != 'y') && (cad != 'N' && cad != 'n'));

                            if (cad == 'Y' || cad == 'y'){

                                printf("\nOkay\n");
                                nc = 3;
                                efoc = '\0';
                            }
                            else if (cad == 'N' || cad == 'n'){

                                printf("\nOkay, thank you for your presence!\n");
                                break;
                            }
                        }
                    }

                    //Caso todas as matrizes tanto para Clientes quanto para Funcionarios estiverem ja armazenando um usuario
                    //Mostrará na tela que o limite maximo para registro de Funcionarios e Clientes foi atingido
                    if ((cn == 2) && (fn == 3)){

                        printf("\nYou reached the maximum capacity of register for employees and clients.\n");
                        break;
                    }

                }while ((cad == 'Y' || cad == 'y') && ((cn < 2) || (fn < 3)));

                efoc = '\0';

                printf("\nEnd of Sing up\n\n"); // Escrevo que é o fim do cadastro


                /*
                    Nas condicoes abaixo mostradas eu verifico se devo retornar o usuario para o login
                    ou para o login de Funcionario ou para o Login de Cliente, se caso a variavel ret_Log
                    tiver o valor inicial, isso significa que na Tela inicial o usuario selecionou 2 - Cadastro
                    então retorno o usuario para a Tela inicial.
                */

                if (ret_Log > 0){

                    if (ret_lo_c > 0){

                        ret_lo_c = 0;
                        goto Log_c;

                    }
                    else if (ret_lo_f > 0){

                        ret_lo_f = 0;
                        goto Log_f;

                    }
                    else{

                        ret_Log = 0;
                        goto Log;  

                    }
                }
                else {

                    goto T_inicio;

                }

            break;

            case '3':
                //Caso a opcao da Tela inicial for 3 eu envio o usuario para o endereço End onde será o fim do programa
                goto End;

            break;

            default:
                //Caso o usuario não digitar nenhum dos caracteres instruidos para ser selecionada, eu falo que deu erro
                printf("\n\nError! You must choose one of the two opitions\nNumber 1, 2 or 3.\n\n");
                a = 0;
        }
    }while(a == 0);

    /*
        Na Tela de menu o usuario que conseguiu fazer o log in encontrará uma unica funcao
        que será "'gerenciar' cadastro", para acessa-la o usuario e instruido a digitar '1'
        dentro da funcao ele poderá selecionar 'F' - FUNCIONARIOS e 'C' - CLIENTES ou '1' para
        voltar a Tela menu. Se o usuario selecionar 'F' ele verá todos os cadastro feitos em
        relaçao aos Funcionarios alem de indicar quantos registros de FUNCIONARIOS foram feitos
        bem como quantos ainda FUNCIONARIOS poderão ser registrados, assim também mostrado caso selecione
        'C'. Para sair desta nova tela e voltar para Tela Menu o usuario devera digita '1'.
        Para sair da Tela Menu o usuario deverá digitar '2', sendo enviado novamente para Tela Inicial.
    */

    /*
        Nessa nova versão foram feitas diferentes telas para determinado login, se for que fizer o login
        for um funcionario ele será direcionado para a tela "T_menu_Fun" onde conseguirá ter acesso ao 
        gerenciamento dos cadastro e posteriormente poderemos adicionar uma opção para gerar relatórios 
        sobre a empresa, mas ainda não está devidamente desenvolvida essa opção.
    */

    /*
        A tela para login como cliente será indicada por "T_menu_Cli" e nela será apresentado alguns produtos,
        porém a opção de compra ainda não está devidamente desenvolvida para execução, mas será um projeto para
        a próxima versão do projeto, sendo incrementado a forma de pagamento e outras funções necessárias que
        colabore para o bom funcionamento do nosso projeto.
    */

    T_menu_Fun:

    opt = '\0';
    efoc = '\0';
    printf("\n------------------------------\n");
    printf("\n\t   Welcome\n");
    printf("\n------------------------------\n");
    printf("\n   1) Gerenciar cadastro\n");
    printf("\n   2) Gerar relatorio\n");
    printf("\n\n   3) Sair\n");
    printf("\n******************************\n");

    do{

        a = 1;
        while (opt == '\n'){
            getchar();
        }

        printf("\nChoose one option: ");
        scanf(" %c[^\n]", &opt);
        getchar();

        if (opt == '1'){

            do{

                G_fc:
                a = 1;
                while (efoc == '\n'){
                    getchar();
                }

                printf("\nWe have two register:\n");
                printf("\n  F - Employee");
                printf("\n  C - Client\n");
                printf("\n 1 - Go to Menu\n");
                printf("\nType F, C or 1: ");
                scanf(" %c[^\n]", &efoc);
                getchar();

                if(efoc != 'F' && efoc != 'f' && efoc != 'C' && efoc != 'c' && efoc != '1'){
                    printf("\nERROR! You must type F or C!\n");
                }

            }while (efoc != 'F' && efoc != 'f' && efoc != 'C' && efoc != 'c' && efoc != '1');

            /*
                Para a escolha das opcoes Funcionarios ou Clientes o programa verificará se primeiro há
                algum registro para a opcao escolhida, caso não ouver nenhum registro o usuario sera
                redirecionado atraves do enderecamento G_fc para a tela das opcoes.
            */

            if (efoc == 'F' || efoc == 'f' && arm_fun > 0){

                printf("\nEMPLOYEE'S REGISTER\n");
                printf("\nThere is/are %d registered", fn + 1);

                if (fn < 3){
                    printf("\nYou can register %d employee(s)", 4 - cont_fun);
                }
                else{
                    printf("\nYou cannot register any employee(s)!");
                }
                
                for (m = 0; m <= fn; m++){

                    if (m == 0){
                        for (n = 0; n < 2; n++){
                            if (n == 0){
                                printf("\nEmployee's user number %d\n\n", m + 1);
                                printf("\nLogin: %s", scf1[n]);
                            }
                            else{
                                printf("\nSenha: %s\n", scf1[n]);
                            }
                        }
                    }
                    else if (m == 1){
                        for (n = 0; n < 2; n++){
                            if (n == 0){
                                printf("\nEmployee's user number %d\n\n", m + 1);
                                printf("\nLogin: %s", scf2[n]);
                            }
                            else{
                                printf("\nSenha: %s\n", scf2[n]);
                            }
                        }
                    }
                    else if (m == 2){
                        for (n = 0; n < 2; n++){
                            if (n == 0){
                                printf("\nEmployee's user number %d\n\n", m + 1);
                                printf("\nLogin: %s", scf3[n]);
                            }
                            else{
                                printf("\nSenha: %s\n", scf3[n]);
                            }
                        }
                    }
                    else if (m == 3){
                        for (n = 0; n < 2; n++){
                            if (n == 0){
                                printf("\nEmployee's user number %d\n\n", m + 1);
                                printf("\nLogin: %s", scf4[n]);
                            }
                            else{
                                printf("\nSenha: %s\n", scf4[n]);
                            }
                        }
                    }
                }

                printf("\nType any key to exit: ");
                getchar();
                goto G_fc;

            }
            else if (efoc == 'F' || efoc == 'f' && arm_fun == 0){

                printf("\nThere is no employee registered!\n");
                goto G_fc;
            }
            if (efoc == 'C' || efoc == 'c' && arm_cli > 0){

                printf("\nCLIENT'S REGISTER\n");
                printf("\nThere is/are %d clients registered", cn + 1);

                if (cn < 2){
                    printf("\nYou can register %d employee(s)", 3 - cont_cli);
                }
                else{
                    printf("\nYou cannot register any employee(s)!");
                }

                for (m = 0; m <= cn; m++){

                    if (m == 0){
                        for (n = 0; n < 2; n++){

                            if (n == 0){
                                printf("\nEmployee's user number %d\n\n", m + 1);
                                printf("\nLogin: %s", scc1[n]);
                            }
                            else{
                                printf("\nSenha: %s\n", scc1[n]);
                            }
                        }
                    }
                    else if (m == 1){
                        for (n = 0; n < 2; n++){

                            if (n == 0){
                                printf("\nEmployee's user number %d\n\n", m + 1);
                                printf("\nLogin: %s", scc2[n]);
                            }
                            else{
                                printf("\nSenha: %s\n", scc2[n]);
                            }
                        }
                    }
                    else if (m == 2){
                        for (n = 0; n < 2; n++){
                            if (n == 0){
                                printf("\nEmployee's user number %d\n\n", m + 1);
                                printf("\nLogin: %s", scc3[n]);
                            }
                            else{
                                printf("\nSenha: %s\n", scc3[n]);
                            }
                        }
                    }
                }

                printf("\nType any key to exit: ");
                getchar();
                goto G_fc;

            } 
            else if (efoc == 'C' || efoc == 'c' && (arm_cli == 0)){

                printf("\nThere is no client registered!\n");
                goto G_fc;
            }
            else if (efoc == '1'){

                goto T_menu_Fun;

            }
        }
        else if (opt == '2'){

            printf("\nWe are working on this option...\n\n");
            printf("Type any key to go to Menu screen:");
            getchar();
            goto T_menu_Fun;
        }
        else if (opt == '3'){

            printf("\nOkay, thank you!\n\nBye!\n\n\n");
            goto T_inicio;
        }
        else{

            printf("\nInvalid option.\n");
            a = 0;
        }

    }while(a == 0);

    T_menu_Cli:

    opt = '\0';
    efoc = '\0';
    printf("\n------------------------------\n");
    printf("\n\t   Welcome\n");
    printf("\n------------------------------\n");
    printf("\n     1) BASIC PLAN \n");
    printf("\n     2) INTERMEDIATE PLAN \n");
    printf("\n     3) PREMIUM PLAN \n");
    printf("\n******************************\n");

    do{

        a = 1;
        while (opt == '\n'){
            getchar();
        }

        printf("\nDo you want to purchase any plan[Y/n]: ");
        scanf(" %c[^\n]", &opt);
        getchar();

        if (opt == 'Y' || opt == 'y'){

            do{

                while(efoc == '\n'){
                    getchar();
                }

                printf("\n     1) BASIC PLAN..............R$300,00 \n");
                printf("\n     2) INTERMEDIATE PLAN.......R$450,00 \n");
                printf("\n     3) PREMIUM PLAN............R$650,00 \n");
                printf("\n\n     0) Go back to Menu \n");
                printf("\nChoose one of the options: "); 
                scanf(" %c[^\n]", &efoc);
                getchar();

                if (efoc == '1' || efoc == '2' || efoc == '3'){
                    printf("\nWe are working on it...\n");
                    printf("\nType any key to go back to menu: ");
                    getchar();
                    goto T_menu_Cli;
                }
                else if (efoc == '0'){
                    printf("\nBye!\n");
                    goto T_menu_Cli;
                }
                else{
                    printf("\nInvalid option\n");
                    a = 0;
                }
            }while(a == 0);
            
        }
        else if (opt == 'N' || opt == 'n'){

            printf("\nOkay, thank you!\n");
            printf("\n\nBye!\n\n\n");
            goto T_inicio;
        }
        else{

            printf("\nInvalid option!\n");
            a = 0;
        }

    }while( a == 0);

    //Este é o fim do programa
    End:
    printf("\nEnd of this Program!\nThank you for your presence\n\nBYE!\n\n");

    return 0;
}