
#ifndef RESULT_H_
#define RESULT_H_

#include <stdlib.h> // for "abs"
#include <math.h> // for "fabs"
#include <cmath> // for "std::abs" and "std::fabs"
#include <iostream>
#include <fstream>
#include "queryparser.h"
#include "DocsInfo.h"
#include "parser/parse_query.h"
#include "Vocabulario.h"
#include "Index.h"
#ifdef __APPLE__ 
#include <unordered_map>
#else
#include <tr1/unordered_map>
#endif

#include <pthread.h>
#include <semaphore.h>
#include <set>

typedef struct result {
    
   //set <int>terms;
    
	int doc_id;
	int num_termos;
	int mask_termos;
	float score;
	float upper_score;

/**/
	bool operator<( const result & d ) const {
  	       return (fabs(score-d.score)<=0.0000001)?(doc_id>d.doc_id):(score > d.score);
  	}
	bool operator>( const result & d ) const {
		       return (fabs(score-d.score)<=0.0000001)?(doc_id<d.doc_id):(score < d.score);
	}
	bool operator<=( const result & d ) const {
	       return (fabs(score-d.score)<=0.0000001)?1:(score > d.score);
	}
	
	bool operator<( const float & d ) const {
      return (fabs(score-d)<=0.0000001)?0:( score > d);
	}
	bool operator>( const float & d ) const {
		  return (fabs(score-d)<=0.0000001)?0:(score > d);
	}
  /**/
	result() {
	}

	result(int d, float _score, float _upper_score, int nt, set<int> st) {
		doc_id = d;
		score = _score;
		upper_score = _upper_score;
		num_termos = nt;
        mask_termos = 0;
       // terms = st;
	}

	result(int d, float _score, int nt, set<int>& st) {
		doc_id = d;
		score = _score;
		num_termos = nt;
        mask_termos = 0;
      //  terms = st;
	}


	result(int d, float _score, float _upper_score, int nt) {
		doc_id = d;
		score = _score;
		upper_score = _upper_score;
		num_termos = nt;
        mask_termos = 0;
	}

	result(int d, float _score, int nt) {
		doc_id = d;
		score = _score;
		upper_score = _score;
		num_termos = nt;
        mask_termos = 0;
	}
} result;

#endif
