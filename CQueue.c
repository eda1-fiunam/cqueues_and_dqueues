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
} CQueue;

CQueue* CQueue_New( size_t n );
void CQueue_Delete( CQueue** this );
void CQueue_Enqueue( CQueue* this, int val );
int CQueue_Dequeue( CQueue* this );
int CQueue_Peek( CQueue* this );
bool CQueue_IsFull( CQueue* this );
bool CQueue_IsEmpty( CQueue* this );
void CQueue_MakeEmpty( CQueue* this );
size_t CQueue_Len( CQueue* this );
size_t CQueue_Capacity( CQueue* this );

CQueue* CQueue_New( size_t _capacity )
{
   return NULL;
}

void CQueue_Delete( CQueue** this )
{
}


void CQueue_Enqueue( CQueue* this, int val )
{

   // esta es una forma de terminar el programa sin incurrir
   // en fugas de memoria:
	// if( this->len == this->capacity ){
	//	  CQueue_Delete( &this );
	//	  assert( 0 );
	// }

   assert( this->len < this->capacity );
}

int CQueue_Dequeue( CQueue* this )
{
   assert( this->len > 0 );
}

int CQueue_Peek( CQueue* this )
{
   assert( this->len > 0 );
}

bool CQueue_IsFull( CQueue* this )
{
}

bool CQueue_IsEmpty( CQueue* this )
{
}

size_t CQueue_Len( CQueue* this )
{
}

size_t CQueue_Capacity( CQueue* this )
{
}

void CQueue_MakeEmpty( CQueue* this )
{
}


//----------------------------------------------------------------------
//  Driver program
//----------------------------------------------------------------------
int main()
{
	CQueue* fila = CQueue_New( 5 );

	printf( "La capacidad de la cola es: %ld\n", CQueue_Capacity( fila ) );

	int miCont = 5;
	while( CQueue_IsFull( fila ) == false ){
		CQueue_Enqueue( fila, miCont );
		printf( "El número de elementos actuales en la cola es: %ld\n", CQueue_Len( fila ) );
		++miCont;
	}
   printf( CQueue_IsEmpty( fila ) ? "La cola está vacía\n" : "La cola no está vacía\n" );
   printf( CQueue_IsFull( fila ) ? "La cola está llena\n" : "La cola no está llena\n" );

	while( CQueue_IsEmpty( fila ) == false ){
		printf( ": %d\n", CQueue_Dequeue( fila ) );
		printf( "El número de elementos actuales en la cola es: %ld\n", CQueue_Len( fila ) );
	}
   printf( CQueue_IsEmpty( fila ) ? "La cola está vacía\n" : "La cola no está vacía\n" );
   printf( CQueue_IsFull( fila ) ? "La cola está llena\n" : "La cola no está llena\n" );

	CQueue_Delete( &fila );
}

