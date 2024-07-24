#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <direct.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#define pfds 10 //valor da promoção do fim de semana (constante)

//variáveis globais
float din=0.0; //carteira
char nomep[50],end[200],dc[10][500]; //nome do usuario, endereço e discos do carrinho
int dds=0,c,i,ii,cc=0,ale=0,numest=0; //dia da semana, carrinho de compras, vetores, confirmação do cadastro, variavel que recebe número aleatório, variável pra escolher disco no estoque

//linhas do início
void linha();
void linha(){
   printf("\n          =======================================\n");
 }

 int dia(); //função que retorna que dia da semana é hoje
 int dia(){
 //struct necessário da biblioteca time.h
   struct tm{
   int tm_sec;
   int tm_min;
   int tm_hour;
   int tm_mday;
   int tm_mon;
   int tm_year;
   int tm_wday;
   int tm_yday;
   int tm_isdst;
   };

   struct tm *data_hora_atual; //nome da struct

   time_t segundos;

   time(&segundos);

   data_hora_atual = localtime(&segundos);

    dds= data_hora_atual->tm_wday; //dds recebe o valor do dia da semana na struct (comando de atribuição)
    return dds;
 }

 //inicializa variáveis e o template das informações do disco que será comprado com nome, gravadora, gênero, músicas, preço, ano de lançamento e a resposta de sim ou não na compra
void discos(char nome [50],char grav [50],char gen [50],char music [200], int preco,int ano,int resp);
void discos(char nome [50],char grav [50],char gen [50],char music [200], int preco,int ano,int resp){

   printf("-> Nome do disco: %s\n",nome);
   printf("-> Gênero Musical: %s\n",gen);
   printf("-> Gravadora do disco: %s\n",grav);
   printf("-> Ano de lançamento: %d\n",ano);
   printf("-> Músicas: %s\n",music);

   //parte da promoção dos fins de semana
   if(dds==6 || dds==7){
        preco=preco-pfds; //operação aritmética
   printf("-> Preço: %d\n",preco);
   }
   else{
        printf("-> Preço: %d\n",preco);
   }
   printf("\nTem certeza que quer continuar com a compra? Digite 1 para sim e finalizar a compra, 2 para não e 3 para adicioná-lo ao carrinho\n"); //confirmação
   scanf("%d",&resp);
   if (resp==1){
    if(preco<=din){
    printf("\nCompra realizada com sucesso e será entregue para sua casa no endereço '%s' entre 20 e 30 dias\nObrigado e volte sempre %s!\n",end,nomep);
    din=din-preco;
    system("pause");
   }
   else{ //se o dinheiro disponível for menor que o preço do disco ele não será comprado
    printf("O preço é maior que o que você está disposto a gastar (R$%.2f), por favor tente outro disco.\n",din);
    system("pause");
   }
   }
   if(resp==3){
        if(preco<=din){
    c++;
    strcpy(dc[ii],nome);
    din=din-preco;
    printf("Disco adicionado com sucesso! Saldo Atual: %.2f\n",din);
    system("pause");
}
        else{
            printf("Não foi possível adicionar o disco ao carrinho;o seu dinheiro atual (%.2f) não é suficiente\n",din);
            system("pause");
        }
   }
   system("cls");
}//se o dinheiro disponível for menor que o preço do disco ele não será comprado

int main(){

   dds=dia();

   int num,est; //inteiros da resposta da tela inicial e resposta da opção do disco

   setlocale(LC_ALL,"Portuguese");

   if(cc==0){//vai mostrar o carregando apenas se for a primeira vez no programa
   for(i=0;i<1;i++){ //for para "carregando..." no início do programa
   printf("Carregando");
   Sleep(500);
   printf(".");
   Sleep(500);
   printf(".");
   Sleep(500);
   printf(".");
   Sleep(500);
   system("cls");
   }
   }
   if(cc==1){
   cc++;
   for(i=0;i<1;i++){ //for para "completando cadastro" após o cadastro
   printf("Completando cadastro");
   Sleep(500);
   printf(".");
   Sleep(500);
   printf(".");
   Sleep(500);
   printf(".");
   Sleep(500);
   system("cls");
   }
   }

//tela inicial do programa
  do{

    Sleep(500);
    linha();
    Sleep(500);
    printf("           Bem vindo à Loja de Discos DISC-CHORD");
    Sleep(500);
    linha();
    Sleep(500);

    switch(dds){ //mostrará o dia da semana (hoje)
       case 1:
    printf("\nDia da semana: Segunda\n");
    break;
       case 2:
    printf("\nDia da semana: Terça\n");
    break;
        case 3:
    printf("\nDia da semana: Quarta\n");
    break;
        case 4:
    printf("\nDia da semana: Quinta\n");
    break;
        case 5:
    printf("\nDia da semana: Sexta\n");
    break;
        case 6:
    printf("\nDia da semana: Sábado\n");
    break;
        case 7:
    printf("\nDia da semana: Domingo\n");
    break;
   }
    //instruções ao usuário
    printf("\nAos fins de semana temos %d.00 reais de desconto em todos os discos\nPressione o número mostrado para abrir a página indicada\nSe não houver um cadastro, por favor faça apertando o número 1\n\n 1- Cadastro\n 2- Estoque Atual\n 3- Carrinho\n 4- Sair\n\n",pfds);
    scanf("%d", &num);

    if(num>4 || num<1){ //caso usuário digitar algum número fora das opções disponíveis
        printf("Opção inválida\n");
        system("pause");
        return main();
    }

   if(num==4){
        return 0; //caso o usuário queira sair do programa
   }

   if(num==1){ //cadastro do usuário
        if(cc==0){
    fflush(stdin);
    printf("\nInsira seu nome: ");
    cc++;
    gets(nomep);
    fflush(stdin);
    printf("\nInforme quanto você está disposto a gastar: ");
    scanf("%f",&din);
    fflush(stdin);
    printf("\nInforme o endereço desejado para entrega das compras: ");
    gets(end);
    fflush(stdin);
    return main();
        }
        else{
            system("cls");
            printf("Opa, calma aí! Você já se cadastrou!\n\n");
            Sleep(900);
            printf("Seu nome é: %s\n\n",nomep);
            Sleep(900);
            printf("Você tem %.2f reais na carteira\n\n",din);
            Sleep(900);
            printf("E seu endereço é: %s\n\n",end);
            system("pause");
            system("cls");
        }
   }
   }while(num==1);

   if(num==3){
        system("cls");
    printf("Você tem %d discos no carrinho, são eles:\n",c);
    for(i=0;i<c;i++){
        printf("%s\n",dc[ii]);
    }//mostra os discos no carrinho e pergunta sobre a finalização da compra
    printf("\nAperte 1 para finalizar a compra ou 2 para continuar comprando: ");
    scanf("%d",&num);
    if(num==1){
        printf("\nCompra finalizada com sucesso! Os discos serão entregues entre 20 e 30 dias no endereço '%s'.\nObrigado e volte sempre %s!\n", end,nomep);
        return 0;
    }
    else{
        system("cls");
        return main();
   }
   }

   if(num==2){ //página de compra de discos mostrando as opções
   do{
    system("cls");
    srand(time(NULL));
    ale=(rand()%10);
   switch(ale){
   case 1:
    printf("A banda com o disco mais vendido atualmente é Queen");
    break;
    case 2:
    printf("A banda com o disco mais vendido atualmente é Gorillaz");
    break;
    case 3:
    printf("A banda com o disco mais vendido atualmente é Kiss");
    break;
    case 4:
    printf("A banda com o disco mais vendido atualmente é Anastacia");
    break;
    case 5:
    printf("A banda com o disco mais vendido atualmente é Adele");
    break;
    case 6:
    printf("A banda com o disco mais vendido atualmente é Katy Perry");
    break;
    case 7:
    printf("A banda com o disco mais vendido atualmente é Calipso");
    break;
    case 8:
    printf("A banda com o disco mais vendido atualmente é Tame Impala");
    break;
    case 9:
    printf("A banda com o disco mais vendido atualmente é Iron Maiden");
    break;
    case 10:
    printf("A banda com o disco mais vendido atualmente é Pink Floyd");
    break;
    case 11:
    printf("A banda com o disco mais vendido atualmente é niLL");
    break;
     case 12:
    printf("A banda com o disco mais vendido atualmente é Beli Remour");
    break;
      case 13:
    printf("A banda com o disco mais vendido atualmente é Gojira");
    break;
    case 14:
    printf("A banda com o disco mais vendido atualmente é Raffa Moreira");
    break;
    case 15:
    printf("A banda com o disco mais vendido atualmente é MGMT");
    break;



   }
    printf(" \n\nDigite o número indicado para prosseguir com a compra de tal disco ou qualquer outro para voltar\n O estoque atual é:\n\n");
    printf(" 1- Queen\n 2- Gorillaz\n 3- Kiss\n 4- Anastacia\n 5- Iron Maiden\n 6- Pink Floyd\n 7- Tame Impala\n 8- Adele\n 9- Katy Perry\n 10- Dire Straits\n 11- niLL\n 12- Beli Remour\n 13- Gojira\n 14- Raffa Moreira\n 15- MGMT\n 16 Sair\n Sua Escolha:[  ]\b\b\b");
    scanf("%d",&est);

    switch(est){ //dependendo da opção selecionada ele mostrará as informações de acordo com o VOID

    case 1:
        printf("Aperte o número indicado para selecionar o disco desejado\n\n");
        printf("1-Greatest Hits\n\n2- Disco 2\n\nSua escolha [ ]\b\b\b");
        scanf("%d",&numest);
        if(numest==1){
    discos("Greatest Hits","Hollywood Records","Rock","Bohemian Rhapsody, Another One Bites The Dust, Killer Queen, Fat Bottomed Girls, Bicycle Race, You're My Best Friend, Don't Stop Me Now, Save Me, Crazy Little Thing Called Love, Somebody To Love, Now I'm Here, Good Old-Fashioned Lover Boy, Play the Game, Flash, Sevens Seas Of Rhye, We Will Rock You, We Are The Champions",400.09,1981,0);
    break;
    }
        else{
    discos("Gorillaz","Parlophone","Electropop","Re-Hash, 5/4, Tomorrow Comes Today, New Genius(Brother), Clint Eastwood, Man Research(Clapper), Punk, Sound Check(Gravity), Double Bass, Rock The House, 19-2000 Latin Simone(Que Pasa Contigo), Starshine,Slow Country, M1 A1",135.00,2001,0);
    break;
        }
    case 2:
    discos("Gorillaz","Parlophone","Electropop","Re-Hash, 5/4, Tomorrow Comes Today, New Genius(Brother), Clint Eastwood, Man Research(Clapper), Punk, Sound Check(Gravity), Double Bass, Rock The House, 19-2000 Latin Simone(Que Pasa Contigo), Starshine,Slow Country, M1 A1",135.00,2001,0);
    break;
    case 3:
    discos("Hot In The Shade","Mercury","Rock/Hard Rock","Rise To It, Betrayed, Hide Your Heart, Prisoner Of Love, Read My Body, Love's A Slap in The Face, Forever, Silver Spoon, Cadillac Dreams, King Of Hearts, The Street Giveth And TheStreet Taketh Away, You Love Me to Hate you, Somewhere Between Heaven And Hell, Little Casear, Boomerang ",145.14,1989,0);
    break;
    case 4:
    discos("Pieces of A Dream","Sony BMG Music Entertainment","Rock/Pop","I'm Outta Love, Not That Kind, Cowboys & Kisses, Made For Lovin' You,Paid My Dues, One Day In Your Life, Why'd You Lie to Me, You'll Never Be Alone, Left Outside Alone, Sick And Tired, Heavy On My Heart, Everything Burns, Pieces of a Dream, In Your Eyes, Club Megamix",48.00,1999,0);
    break;
    case 5:
    discos("Seventh Son of a Seventh Son","Capitol Records","Heavy Metal","Moonchild, Infinite Dreams, Can I Play with Madness, The Evil That Men Do, Seventh Son of a Seventh Son, The Prophecy, The Clairvoyant, Only The Good Die Young",149.00,1988,0);
    break;
    case 6:
    discos("The Dark Side of the Moon","Capitol Records","Rock Clássico","Speak To Me, Breathe(In the Air), On the Run, Time, The Great Gig In the Sky, Money, Us and Them, Any Colour You Like, Brain Damage, Eclipse",376.50,1973,0);
    break;
    case 7:
    discos("Currents","Modular Recordings","Ambiente","Let It Happen, Nangs, The Moment, Yes I'm Changing, Eventually, Gossip, The Less I know The Better, Past Life, Disciples, 'Cause I'm A Man, Reality In Motion, Love/Paranoia, New Person, Same Old Mistakes",345.00,2015,0);
    break;
    case 8:
    discos("21","XL Recordings Ltd","Pop","Rolling in the Deep, Rumour Has It, Turning Tables, Don't You Remember, Set  Fire to the Rain, He Won't Go, Take It All, I'll Be Waiting, One And Only, Lovesong, Someone Like You" ,190.63,2011,0);
    break;
    case 9:
    discos("Prism","Capitol records, LLC","Pop","Roar, Legendary Lovers, Birthday, Walking On Air, Unconditionally, Dark Horse, This Is How We Do, International Smile, Ghost, Love Me, This is Moment, Double Rainbow, By The Grace of God, Spiritual, It Takes Two, Choose Your Battles",108.00,2013,0);
    break;
    case 10:
    discos("Brothers in Arms","Mercury Records Limited","Rock","So Far Away, Money for Nothing, Walk Of Life, Your Latest Trick, Why Worry?, Ride Across The River, The Man's Too Strong, One World, Brothers In Arms",407.22,1985,0);
    break;
    case 11:
    discos("Regina","SoundFood Gang", "Rap","452(intro), Wi-Fi, Meliodas, Minha mulher acha que eu sou o Brad Pitt, Stay High, De novo e De novo, Valete de Copas, Jovens telas trincadas, Loopers, Atari Level 2, Summer Nights, 1690293 ( Interlúdio), Nego Drama Pt.ll, Tchau, Regina",200.00,2017,0);
    break;
    case 12:
    discos("O minimaslismo é rosa","Polvo Roxo","R&B","Deus, Mães e coraline, O toque, A outra, Superficial, Mar, Não me prendo a nada, Pior forma, Eu vi",325.00, 2018, 0);
    break;
    case 13:
    discos("L'Enfant Sauvage","Roadrunner Records","Death Metal Progressivo", "Explosia, L'enfant sauvage, The Axe, Liquid Fire, The Wild Healer, Planned, Obsolesnce, Mouth of Kala, The Gift of Guilt, Pain Is a Master, Born in WInter, The Fall, This Emptiness, My Last Creation", 245.55,2012,0);
    break;
    case 14:
    discos("Rock-Star Mixtape","Raffa Moreira","Trap","Rock-Star, Indo, Print na briga, T.O.P.O., 28 swag, Afff",180.75,2016,0);
    break;
    case 15:
    discos("Little Dark Age","MGMT","Electro","She Works Out Too Much, Little Dark Age, When You Die, Me and Michael, TSLAMP, James, Days That Got Away, One Thing Left to Try, When You´re Small, Hand It Over",120.45, 2017,0);
    break;
    default:
        system("cls");

    }


}while (est!=16);
    return main();
   }
}
