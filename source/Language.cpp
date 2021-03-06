#include "Language.h"
#include <string>
#include <iostream>

Noun::Noun()
{
	ID = 0;
	Data = 0;
	Numeral = 0;
	GenitiveNoun = NULL;
	IsPlural = false;
	PreposNum = 0;
	RelativeClause = NULL;
	IsRelativeClauseEssential = false;
	RelativeClauseObj = 0;
	IsReflexive = false;
	ArticleType = 0;
	ShouldUseGenitive = false;
	ShouldUseRelativeClause = false;
	for (int i = 0; i < 16; ++i)
	{
		Adjectives[i] = 0;
	}
}

void Noun::addAdjective(int adjectiveNum)
{
	for (int i = 0; i < 16; ++i)
	{
		if (Adjectives[i]==0)
		{
			Adjectives[i] = adjectiveNum;
			break;
		}
	}
}

Noun::~Noun()
{
	if (ShouldUseGenitive && GenitiveNoun != NULL)
	{
		delete GenitiveNoun;
	}
}

Language::Language() : LangID("lang")
{
	NewSentence();
}

Language::Language(std::string LangID) : LangID(LangID)
{
	NewSentence();
}

Language::~Language()
{
}

std::string Language::createSentence(){
	return "";
}
std::string Language::createSubClause(){
	return "";
}
Noun* Language::getIt(int id){
	Noun * n = new Noun;
	n->ID=5;
	n->Numeral=0;
	n->IsPlural=false;
	n->IsReflexive=false;
	n->ShouldUseRelativeClause=false;
	n->ShouldUseGenitive=false;
	n->ArticleType=0;
	for (int i = 0; i < 16; ++i)
	{
		n->Adjectives[i]=0;
	}
	return n;
}

void Language::NewSentence(){
	Data = 0;
	Capital = true;
	Punctuation = true;
	Question = 0;
	IsClause=false; 
	ExtVerb1 = 0;
	ExtVerb2 = 0;
	ExtVerb3 = 0;
	Conjunction=0;
	NumFilledSubjects=-1;
	Verb1=0;
	Verb2=0;
	Verb3=0;
	st=1;
	Negate=false;
	SubConjunctionType = 0;
	for (int i = 0; i < 8; ++i)
	{  
		ObjConjunctionType[i] = 0;
		NumFilledObjects[i] = -1;
	}
}
