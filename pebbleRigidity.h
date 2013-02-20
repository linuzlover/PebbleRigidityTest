/* 
 * File:   pebbleRigidity.h
 * Author: sickboy
 *
 * Created on February 20, 2013, 5:13 PM
 */

#ifndef PEBBLERIGIDITY_H
#define	PEBBLERIGIDITY_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdlib.h>


int isRigid;
int num_ind;
int **ind_set;

void init_rigidity_check();

void close_rigidity_check();

#ifdef	__cplusplus
}
#endif

#endif	/* PEBBLERIGIDITY_H */

