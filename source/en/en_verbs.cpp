#include "../settings.h"
#include "en.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

std::string en::GetVerbPreAdd(int VerbNum)
{
	std::ifstream is (DICTIONARY EN_EN_FOLDER "verb_present");
	if (GotoLine(is,VerbNum)) return "";
	int Data = is.get();
	if (Data == '1')
	{
		if (GotoSegment(is,2)) return "";
		std::string Segment = GetSegment(is);
		is.close();
		return Segment;
	}
	else if (Data == '0')
	{
		if (GotoSegment(is,11)) return "";
		std::string Segment = GetSegment(is);
		is.close();
		return Segment;
	}
	else
	{
		if (GotoSegment(is,1)) return "";
		std::string Segment = GetSegment(is);
		is.close();
		//Now follow all the english spelling rules
		//http://www.oxforddictionaries.com/words/verb-tenses-adding-ed-and-ing
		//http://www.grammar.cl/Notes/Spelling_ING.htm
		int u = Segment.length();
		if (Segment[u-1] == 'e' && Segment[u-2] == 'i')
		{
			//Turn 'ie' into y
			Segment = Segment.substr(0,u-2);
			Segment += "y";
		}
		else if (Segment[u-1] == 'e' && ( Segment[u-2] != 'e' && Segment[u-2] != 'y' && Segment[u-2] != 'o' ))
		{
			//Drop final e, if e is not before y,e or o
			//make -> mak ( + {ed,ing} )
			Segment = Segment.substr(0,u-1);
		}
		else if (Segment[u-1] == 'c')
		{
			//Add a k after a c
			//picnic -> picnick ( + {ed,ing} )
			Segment += "k";
		}
		else if (!IsVowel(Segment[u-3]) && IsVowel(Segment[u-2]) && !IsVowel(Segment[u-1]) && Segment[u-1]!='x' && Segment[u-1]!='y' && Segment[u-1]!='z' && Segment[u-1]!='w')
		{
			//Double consonant after consonant-vowel-consonant cluster.
			//Provided that final consonant is not w,x,y or z
			//Travel -> Travell ( + {ed,ing} )
			Segment += Segment[u-1];
		}
		return Segment;
	}
	return "";
}


std::string en::GetVerbSimplePresent(int VerbForm, int VerbNum)
{
#ifdef DEBUG
	std::cout << "[EN] GetVerbSimplePresent(int VerbForm = " << VerbForm << " , int VerbNum = " << VerbNum << " ) " << std::endl;
#endif
	std::ifstream is(DICTIONARY EN_EN_FOLDER "verb_present");
	if (GotoLine(is,VerbNum)) return "";
	int Data = is.get();
	if (Data == '0')
	{
		if (GotoSegment(is,VerbForm+1)) return "";
		std::string Segment = GetSegment(is);
		is.close();
		return Segment;
	}
	else
	{
		if (GotoSegment(is,1)) return "";
		std::string Segment = GetSegment(is);
		if (Data != '3')
		{
			if (VerbForm > 2 && VerbForm < 6)
			{
				//Need to add 's' conjugation
				int u = Segment.length();
				if (Segment[u-1]=='o' || (Segment[u-1]=='s' && Segment[u-2]=='s') || (Segment[u-1]=='h' && Segment[u-2]=='s') || (Segment[u-1]=='h' && Segment[u-2]=='c') || (Segment[u-1]=='z' && Segment[u-2]=='z') || Segment[u-1]=='x')
				{
					Segment +="e";
				}
				Segment += "s";
			}
		}
		is.close();
		return Segment;
	}
	is.close();
	return "";
}

std::string en::GetVerbPresentProgressive(int VerbForm, int VerbNum)
{
	return GetVerbSimplePresent(VerbForm,1) + " " + GetVerbPreAdd(VerbNum) + "ing";
}

std::string en::GetVerb(noun& Noun, int snum, int VerbNum, int SentenceType)
{
#ifdef DEBUG
	std::cout << "[EN] GetVerb(noun& Noun, int snum = " << snum << " , int VerbNum = " << VerbNum << " , int SentenceType = " << SentenceType << " )" << std::endl;
#endif
	//First we need to figure out which form of a verb we need.
	//We can do this with Noun and snum information.
	//Then we need to get the verb string from the appropriate function, and return it.
	//We can do this with VerbNum and SentenceType information.
	int VerbForm;
	if (Noun.id < 10 && Noun.id > 0) VerbForm = Noun.id;
	else if (snum > 0 || Noun.plural) VerbForm = 8;
	else if (snum < 0) VerbForm = 0;
	else VerbForm = 5;
#ifdef DEBUG
	std::cout << "[EN] VerbForm = " << VerbForm << std::endl;
#endif
	return GetVerbPresentProgressive(VerbForm,VerbNum);
}