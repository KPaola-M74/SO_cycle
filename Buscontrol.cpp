/*
Archivo:Buscontrol.cpp
  Autoras:
    Karen Paola Moreno Palacios 201940254
   
  Emails: 
    moreno.Karen@correounivalle.edu.co
    

  Versión: 1
  Licencia: GPL
*/
#include "Buscontrol.h"
#include "iostream"
#include "string"
#include<algorithm>
#include <sstream>

using namespace std;

Buscontrol::Buscontrol(string name )
{
  memoriaA[0]=0;
  memoriaA[1]=0;
  memoriaA[2]=0;
  memoriaA[3]=0;
  memoriaA[4]=0;
  memoriaA[5]=0;
  memoriaA[6]=0;
  memoriaA[7]=0;
  registroAcumulador[0]=0;
  nombreMemoria[0]="";
  nombreMemoria[2]="";
  nombreMemoria[3]="";
  nombreMemoria[4]="";
  nombreMemoria[5]="";
  nombreMemoria[6]="";
  nombreMemoria[7]="";
  nombreMemoria[1]="";





  



}
 


void  Buscontrol::memoriaAsig(string nombre)

{ 

  bool present = false;
  string  key = nombre;

  for(int i =0; i >0; i++)
  {
    if(nombreMemoria[i] == key)
    {
      present = true;
      break;
    
    }
  }  
  if (present)
  {
    cout << "The element is present";
  }
  else
  {
    nombreMemoria[aux]=nombre;
    aux++;
  }

 
  
} 
  void  Buscontrol::dirrecion (string dirre) 
{
  if(dirre ==nombreMemoria[0]) 
  {
     conteo =0;
  } 
  else if (dirre==nombreMemoria[1]) 
  {
    	conteo =1;
  }
  else if(dirre==nombreMemoria[2]) 
  {
    	conteo =2;  	
  }
  else if(dirre==nombreMemoria[3])
  {
    conteo=3;  	
  }
  else if(dirre==nombreMemoria[4]) 
  {    	
    conteo=4;
  }
  else if(dirre==nombreMemoria[5]) 
  {  	
    	conteo=5;
  } 
  else if(dirre==nombreMemoria[6]) 
  {
    	conteo=6;  	
  } 
  else if(dirre==nombreMemoria[7]) 
  {
    conteo=7;  	
  } 
  else 
  {
    	
    conteo=-1;
  }   
    	
    	
}

void Buscontrol:: unidadcontrol(string instruccion,string DireccionMemoria,string  numero,string entrada,string entrada2) 
{

  int num1;
  /*SET - MEM - SET D1 X NULL NULL, Store X value in in D1 memory     address. where X is an immediate, direct or constant value.     When     SET instruction is read the X value is stored in Memory without     processor execution.

  */
	if(instruccion=="SET") 
  {
		//boolean isNumeric = numero.matches("[+-]?\\d*(\\.\\d+)?");
		//cuebra que efectivamente es un valor el que se esta asignando 
	  if(numero!= "NULL" &&   istringstream(numero)>>num1) 
    {
			 
		  //int numEntero = Integer.parseInt(numero);
			memoriaAsig(DireccionMemoria);
			dirrecion (DireccionMemoria);
			int  memoria = conteo;
			memoriaA[memoria]=num1;
     //cout << "EN MEMORIA : "<< conteo<<" : " << memoriaA[memoria]         << endl;
		 
		}
		  
		 
  }
  /*LDR - LOAD - LDR D3 NULL NULL Load the value in D3 memory address and puts in acumulator register*/
  
	if(instruccion=="LDR") 
  {
		  
		dirrecion (DireccionMemoria);
		int  memoria2 = conteo;
		registroAcumulador [0]=memoriaA[memoria2];  
	} 
  /*ADD - ADDITION - There are three ways: ADD D1 NULL NULL, adds the value in D1 memory address to loaded value in accumulator register. ADD D1 D3 NULL Load the value in D1 memory address in the acumulator register and adds to found value in D3 memory address. ADD D1 D3 D4 same that ADD D1 D3 but puts the result in D4*/
  if(instruccion=="ADD") 
  {
    if( numero == "NULL")
    {
      dirrecion (DireccionMemoria);
		  int  memoria = memoriaA[conteo];
		  int copia= registroAcumulador[0];
		  int sum = memoria+copia;
		  registroAcumulador[0]= sum;
      //cout<<"RESGISTRO SUMA :" <<registroAcumulador[0]<<endl;
      //cout << " YES " << entrada2 << endl;
       
    } //SEGUNDA FORMA
    else if(numero!="NULL"&& entrada=="NULL")
    {
      dirrecion (DireccionMemoria);
		  int  memoria = memoriaA[conteo];
      dirrecion (numero);
      int  memoria2 = memoriaA[conteo];
		  //int copia= registroAcumulador[0];
      int sum = memoria+memoria2;          
      registroAcumulador[0]= sum;

    }
    else if (entrada!="NULL")
    {

      dirrecion (DireccionMemoria);
		  int  memoria = memoriaA[conteo];
      dirrecion (numero);
      int  memoria2 = memoriaA[conteo];
		  int copia=memoria+memoria2;
      dirrecion(entrada);
       memoriaA[conteo]=copia;
    }
       
      
	
  } 
  /*STR - STORE - STR D3 NULL NULL Read the value in acumulator register and puts in D3 memory address*/
  if(instruccion=="STR") 
  {
		 
		  
	  int numeroAcumalado= registroAcumulador[0];
		string numCadena= to_string(numeroAcumalado);
		registroAcumulador[0]=0;
		// cout << " MEMORIA CARGADA " <<DireccionMemoria << " | "<< endl;
		unidadcontrol("SET",DireccionMemoria,numCadena,"NULL","NULL");
				
	}
  /*SHW - SHOW - SHW D2 NULL NULL show the value in D2 memory address, SHW ACC show the value in acumulator register, SHW ICR show the value in ICR register, SHW MAR show the value in MAR register, SHW MDR show the value in MDR register, SHW UC show the value in Control Unit.

*/
  if(instruccion=="SHW") 
  {
		dirrecion (DireccionMemoria);
    cout <<memoriaA[conteo]<<endl; 
	
		 
	} /*END - FINISH READING INSTRUCTION*/
  if(instruccion=="END")
  {
  
  }
	 /*SUB - SUBTRACTION - There are three ways: SUB D1 NULL NULL, SUB D1 D2 NULL and SUB D3 D2 D1 smiliar to ADD but perform subtraction*/
  if(instruccion=="SUB") 
  {
    if( numero == "NULL")
    {
      dirrecion (DireccionMemoria);
		  int  memoria = memoriaA[conteo];
		  int copia= registroAcumulador[0];
		  int rest = copia-memoria;
		  registroAcumulador[0]= rest;
		  //cout << " RESTA " << registroAcumulador[0] << endl;
       
    } 
    else if(numero!="NULL"&& entrada=="NULL")
    {
      dirrecion (DireccionMemoria);
		  int  memoria = memoriaA[conteo];
      dirrecion (numero);
      int  memoria2 = memoriaA[conteo];
		  int copia= registroAcumulador[0];
      int sum = memoria-memoria2;          
      registroAcumulador[0]= sum;

    }
    else if (entrada!="NULL")
    {
      
      dirrecion (DireccionMemoria);
		  int  memoria = memoriaA[conteo];
      dirrecion (numero);
      int  memoria2 = memoriaA[conteo];
		  int copia=memoria-memoria2;
      dirrecion(entrada);
      memoriaA[conteo]=copia;
    }
       
      
	
  }    
  /*MUL - MULTIPLICATION - Using ADD perform multiplication operation. There are three ways: MUL D1 NULL NULL, MUL D1 D2 NULL, MUL D1 D2 D3 similar to ADD and SUB. Multiplication cannot be used with an immediate/direct/constant value.*/
  if(instruccion=="MUL") 
  {
    if( numero == "NULL")
    {
      dirrecion (DireccionMemoria);
		  
		  int  memoria = memoriaA[conteo];
		  int copia= registroAcumulador[0];
      registroAcumulador[0] =0;
      //cout<<"ACUMULADOR :"<<copia<<endl;
      for(int j=0; j<copia;j++ )
      {
          //cout<<j <<endl;
        		            unidadcontrol("ADD",DireccionMemoria,"NULL","NULL","NULL");

      }
		  
       //cout<<"RESGISTRO :" <<registroAcumulador[0];


      
      } // caso 2
    else if(numero!="NULL"&& entrada=="NULL")
    {
      dirrecion (DireccionMemoria);
		  int  memoria = memoriaA[conteo];
      dirrecion (numero);
      int  memoria2 = memoriaA[conteo];
		  //int copia= registroAcumulador[0];
      
      //int sum = memoria*copia*memoria2;          
      registroAcumulador[0]= memoria;
      

      for(int j=0; j< memoria2-1;j++ )
      {
         // cout<<j <<endl;
        		            unidadcontrol("ADD",DireccionMemoria,"NULL","NULL","NULL");

      }
    //cout<<"FINAL : " << registroAcumulador[0]<<endl;
      
    }else if (entrada!="NULL")
    {
      int copiaRegistroAcumulador = registroAcumulador[0];
       dirrecion (DireccionMemoria);
		    int  memoria = memoriaA[conteo];
        dirrecion (numero);
        int  memoria2 = memoriaA[conteo];
		    registroAcumulador[0]= memoria;

      for(int j=0; j< memoria2-1;j++ )
      {
          cout<<j <<endl;
        		            unidadcontrol("ADD",DireccionMemoria,"NULL","NULL","NULL");

      }
        cout<<"FINAL : " << registroAcumulador[0]<<endl;

      
      
        
         dirrecion(entrada);
         memoriaA[conteo]=registroAcumulador[0];

      registroAcumulador[0] = copiaRegistroAcumulador;
      
    }
       
      
	
  } 
  /*DIV - INTEGER DIVISION - Using SUB perform division operation.*/
  if(instruccion=="DIV") 
  {
    //PRIMER CASO .
    if( numero == "NULL")
    {
      dirrecion (DireccionMemoria);
		  int  memoria = memoriaA[conteo];
		  int copia= registroAcumulador[0];
      
      //Acumulador = dividendo
      //memory = divisor

      //Acumulador = 5
      //memory= 3
      // 5/ 3 =  1
      int cociente = 0;
      while ( registroAcumulador[0] > memoria)
        {
          unidadcontrol("SUB",DireccionMemoria,"NULL","NULL","NULL");
          cociente ++;

      }
      registroAcumulador[0]= cociente;
      //cout << "DIV "<<registroAcumulador[0]<<endl;
    }

    
    else if(numero!="NULL"&& entrada=="NULL")
    {

       dirrecion (DireccionMemoria);
		  int  memoria = memoriaA[conteo];
      dirrecion (numero);
      int  memoria2 = memoriaA[conteo];
		          
      registroAcumulador[0]= memoria;

      //dividendo = memoria
      //divisor = memoria2
      int cociente = 0;
      while(registroAcumulador[0] > memoria2 )
      {
        		            unidadcontrol("SUB",numero,"NULL","NULL","NULL");
        cociente ++;

      }
      registroAcumulador[0] = cociente;
      //cout << "DIV "<<registroAcumulador[0]<<endl;

      

      
    }
     else if (entrada!="NULL")
    {
        int copiaRegistroAcumulador = registroAcumulador[0];
       dirrecion (DireccionMemoria);
		    int  memoria = memoriaA[conteo];
        dirrecion (numero);
        int  memoria2 = memoriaA[conteo];
		    registroAcumulador[0]= memoria;

      int cociente = 0;
      while(registroAcumulador[0]> memoria2 )
      {
          
        		unidadcontrol("SUB",numero,"NULL","NULL","NULL");
            cociente ++;

      }
        
       // cout<<"FINAL : " << registroAcumulador[0]<<endl;

        
         dirrecion(entrada);
         memoriaA[conteo]=cociente;

      registroAcumulador[0] = copiaRegistroAcumulador;
      

    }
    
  }
  /*INC - INCREMENT - INC D3 NULL NULL Load the value in D3 memory address adds 1 and store in same address*/
  if(instruccion=="INC")
  {

     dirrecion (DireccionMemoria);
		int  memoria = memoriaA[conteo]+1;
     memoriaA[conteo]= memoria;
    
  }
  /*DEC - DECREMENT - DEC D3 NULL NULL Load the value in D3 memory address adds 1 and store in same address*/
  if(instruccion=="DEC")
  {

     dirrecion (DireccionMemoria);
		int  memoria = memoriaA[conteo]-1;
     memoriaA[conteo]= memoria;
    
  }
  /*MOV - MOVE - MOV D2 D10 NULL Load the value in D2 memory address to D10 memory address and clear D2 address*/
  if(instruccion=="MOV")
  {

     dirrecion (DireccionMemoria);
		    int  memoria = memoriaA[conteo];
      dirrecion (numero);
        memoriaA[conteo]= memoria;
    dirrecion (DireccionMemoria);
        memoriaA[conteo]= 0;

      
    
  }
  /*BEQ - EQUAL - BEQ D10 NULL NULL Load the value in D10 memory address if substration with acumulator register values is zero puts in D10 memory address. There are three ways: BEQ D10 NULL NULL, BEQ D1 D10 NULL, BEQ D1 D2 D3 */
  if(instruccion=="BEQ") 
  {
    //PRIMER CASO .
    if( numero == "NULL")
    {
      dirrecion (DireccionMemoria);
		  int  memoria = memoriaA[conteo];
		  int copia= registroAcumulador[0];

      int rest = copia -memoria;
      if (rest == 0){
        memoriaA[conteo] = 0;
      }
      
     
    }

    //SEGUNDO CASO
    else if(numero!="NULL"&& entrada=="NULL")
    {

       dirrecion (DireccionMemoria);
		  int  memoria = memoriaA[conteo];
      dirrecion (numero);
      int  memoria2 = memoriaA[conteo];

      int rest = memoria - memoria2;
      if(rest == 0)
      {
       dirrecion (DireccionMemoria);
        memoriaA[conteo] = 0;
      }
		          
     
    }
      //TERCER CASO
     else if (entrada!="NULL")
    {
       
       dirrecion (DireccionMemoria);
		    int  memoria = memoriaA[conteo];
        dirrecion (numero);
        int  memoria2 = memoriaA[conteo];
        int rest = memoria - memoria2;
      
        if (rest ==0)
        {
          dirrecion(entrada);
          memoriaA[conteo] =0;
        }
        
         

      

    }
    
  }


  
 

    
  }



    


     



void Buscontrol::entrada(){


  
  
  


  string cadena;
   string entrada1, entrada2, entrada3, entrada4,entrada5;
  do
  {

     
    cout <<"";
    std::getline(cin, cadena);

    stringstream input_stringstream(cadena); // Convertir la cadena a un stream                     

   
    // Extraer
    getline(input_stringstream,entrada1,' ');
    getline(input_stringstream, entrada2,' ');
    getline(input_stringstream, entrada3,' ');
    getline(input_stringstream, entrada4,' ');
    getline(input_stringstream, entrada5,' ');
    unidadcontrol(entrada1,entrada2,entrada3,entrada4,entrada5);

    
  }
  while( entrada1 != "END");
 
}

  
/*
SET D5 12 NULL NULL
SET D2 23 NULL NULL
SET D8 3 NULL NULL
SET D3 5 NULL NULL
LDR D2 NULL NULL NULL
ADD D5 NULL NULL NULL
ADD D8 NULL NULL NULL
STR D3 NULL NULL NULL
LDR D3 NULL NULL NULL
ADD D2 NULL NULL NULL
STR D2 NULL NULL NULL
SHW D2 NULL NULL NULL
END NULL NULL NULL
  
SET D352 12 NULL NULL
SET D200 23 NULL NULL
SET D310 30 NULL NULL
SET D315 53 NULL NULL
LDR D200 NULL NULL
ADD D352 NULL NULL
ADD D310 NULL NULL
STR D315 NULL NULL
LDR D315 NULL NULL
ADD D200 NULL NULL
STR D200 NULL NULL
SHW D200 NULL NULL
END NULL NULL NULL
*/
