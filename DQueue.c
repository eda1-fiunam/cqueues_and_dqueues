/*Copyright (C) 
 * 2020 - francisco dot rodriguez at ingenieria dot unam dot edu
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */



#include <stdio.h>
// para printf

#include <stdlib.h>
// para malloc and friends

#include <stdbool.h>
// para bool, true y false

#include <assert.h>
// para assert

typedef struct
{
	int* queue;
	size_t front;
	size_t back;
	size_t len;
	size_t capacity;
} DQueue;

DQueue* DQueue_New(           size_t capacity );
void    DQueue_Delete(        DQueue** this );
void    DQueue_Enqueue_back(  DQueue* this, int val );
void    DQueue_Enqueue_front( DQueue* this, int val );
int     DQueue_Dequeue_back(  DQueue* this );
int     DQueue_Dequeue_front( DQueue* this );
int     DQueue_Peek_front(    DQueue* this );
int     DQueue_Peek_back(     DQueue* this );
bool    DQueue_IsFull(        DQueue* this );
bool    DQueue_IsEmpty(       DQueue* this );
void    DQueue_MakeEmpty(     DQueue* this );
size_t  DQueue_Len(           DQueue* this );
size_t  DQueue_Capacity(      DQueue* this );



DQueue* DQueue_New( size_t capacity )
{
   return NULL;
}

void DQueue_Delete( DQueue** this )
{
}


void DQueue_Enqueue_back( DQueue* this, int val )
{

   // esta es una forma de terminar el programa sin incurrir
   // en fugas de memoria:
	// if( this->len == this->capacity ){
	//	  DQueue_Delete( &this );
	//	  assert( 0 );
	// }

   assert( this->len < this->capacity );
}

void DQueue_Enqueue_front( DQueue* this, int val )
{
   assert( this->len < this->capacity );
}

int DQueue_Dequeue_back( DQueue* this )
{
   assert( this->len > 0 );
}

int DQueue_Dequeue_front( DQueue* this )
{
   assert( this->len > 0 );
}

int DQueue_Peek( DQueue* this )
{
   assert( this->len > 0 );
}

bool DQueue_IsFull( DQueue* this )
{
}

bool DQueue_IsEmpty( DQueue* this )
{
}

size_t DQueue_Len( DQueue* this )
{
}

size_t DQueue_Capacity( DQueue* this )
{
}

void DQueue_MakeEmpty( DQueue* this )
{
}


//----------------------------------------------------------------------
//  Driver program
//----------------------------------------------------------------------
int main()
{
	DQueue* fila = DQueue_New( 5 );

	printf( "La capacidad de la cola es: %ld\n", DQueue_Capacity( fila ) );

	int miCont = 5;
	while( DQueue_IsFull( fila ) == false ){
		DQueue_Enqueue_back( fila, miCont );
		printf( "El número de elementos actuales en la cola es: %ld\n", DQueue_Len( fila ) );
		++miCont;
	}
   printf( DQueue_IsEmpty( fila ) ? "La cola está vacía\n" : "La cola no está vacía\n" );
   printf( DQueue_IsFull( fila ) ? "La cola está llena\n" : "La cola no está llena\n" );

	while( DQueue_IsEmpty( fila ) == false ){
		printf( ": %d\n", DQueue_Dequeue_front( fila ) );
		printf( "El número de elementos actuales en la cola es: %ld\n", DQueue_Len( fila ) );
	}
   printf( DQueue_IsEmpty( fila ) ? "La cola está vacía\n" : "La cola no está vacía\n" );
   printf( DQueue_IsFull( fila ) ? "La cola está llena\n" : "La cola no está llena\n" );

	DQueue_Delete( &fila );
}

