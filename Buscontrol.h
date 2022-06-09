/*
Archivo:Buscontrol.h
  Autoras:
    Karen Paola Moreno Palacios 201940254
   
  Emails: 
    moreno.Karen@correounivalle.edu.co
    

  Versión: 1
  Licencia: GPL
*/
#include <vector>
#include <string>
using namespace std;

#ifndef BARCA_H
#define BARCA_H

class Buscontrol 
{
  protected:
 
  
    
  int registroAcumulador[1];
  int memoriaA[8];// este caso puntual  son  8
  string nombreMemoria[8];
  int contadorRegistro=0,conteo=0,aux=0;
   
  public:

  /**
   * @brief  le da valores iniciales a su atributos.
   * @param name
   * @param  
   * @return void
  */
 Buscontrol(string name);
  /**
   * @brief le asigna un ide a cada dirrecion de memoria
   * @param string dirrecion.
   * @param  
   * @return void 
  */
 virtual void  dirrecion(string dirre);
/**
   * @brief   ejecuta las intrucciones dadas.
   * @param  string ,string,string,string,string,
   * @param  
   * @return  void
  */
 virtual void  unidadcontrol(string instruccion,string       
 DireccionMemoria,string  numero,string entrada,string entrada2);
/**
   * @brief  asigana cada memoria a en un array.
   * @param string.
   * @param  
   * @return void
  */ 
virtual void memoriaAsig(string nombre);  
/**
   * @brief  recibe los parametros por consola.
   * @param void. 
   * @param  void.
   * @return void
  */ 
 virtual void entrada();
  

};


#else
class Buscontrol;
#endif