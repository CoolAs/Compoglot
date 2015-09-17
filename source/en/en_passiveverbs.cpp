#include "../settings.h"
#include "en.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

std::string en::GetVerbPassivePresentProgressive(int VerbForm, int VerbNum)
{
#ifdef DEBUG
	std::cout << "[EN] GetVerbPassivePresentProgressive(int VerbForm = " << VerbForm << " , int VerbNum = " << VerbNum << " )" << std::endl;
#endif
	return GetVerbPresentProgressive(VerbForm,1) + " " + GetVerbPastSimple(0,VerbNum);
}

std::string en::GetVerbPassivePresentSimple(int VerbForm, int VerbNum)
{
#ifdef DEBUG
	std::cout << "[EN] GetVerbPassivePresentSimple(int VerbForm = " << VerbForm << " , int VerbNum = " << VerbNum << " )" << std::endl;
#endif
	return GetVerbPresentSimple(VerbForm,1) + " " + GetVerbPastSimple(0,VerbNum);
}

std::string en::GetVerbPassivePastSimple(int VerbForm, int VerbNum)
{
#ifdef DEBUG
	std::cout << "[EN] GetVerbPassivePastSimple(int VerbForm = " << VerbForm << " , int VerbNum = " << VerbNum << " )" << std::endl;
#endif
	return GetVerbPastSimple(VerbForm,1) + " " + GetVerbPastSimple(0,VerbNum);
}

std::string en::GetVerbPassivePastProgressive(int VerbForm, int VerbNum)
{
#ifdef DEBUG
	std::cout << "[EN] GetVerbPassivePastProgressive(int VerbForm = " << VerbForm << " , int VerbNum = " << VerbNum << " )" << std::endl;
#endif
	return GetVerbPastProgressive(VerbForm,1) + " " + GetVerbPastSimple(0,VerbNum);
}

std::string en::GetVerbPassivePastPerfect(int VerbForm, int VerbNum)
{
#ifdef DEBUG
	std::cout << "[EN] GetVerbPassivePastPerfect(int VerbForm = " << VerbForm << " , int VerbNum = " << VerbNum << " )" << std::endl;
#endif
	return GetVerbPastPerfect(VerbForm,1) + " " + GetVerbPastSimple(0,VerbNum);
}

std::string en::GetVerbPassivePastPerfectProgressive(int VerbForm, int VerbNum)
{
#ifdef DEBUG
	std::cout << "[EN] GetVerbPassivePastPerfectProgressive(int VerbForm = " << VerbForm << " , int VerbNum = " << VerbNum << " )" << std::endl;
#endif
	return GetVerbPastPerfectProgressive(VerbForm,1) + " " + GetVerbPastSimple(0,VerbNum);
}

std::string en::GetVerbPassiveFutureSimple(int VerbForm, int VerbNum)
{
#ifdef DEBUG
	std::cout << "[EN] GetVerbPassiveFutureSimple(int VerbForm = " << VerbForm << " , int VerbNum = " << VerbNum << " )" << std::endl;
#endif
	return GetVerbFutureSimple(VerbForm,1) + " " + GetVerbPastSimple(0,VerbNum);
}

std::string en::GetVerbPassiveFutureProgressive(int VerbForm, int VerbNum)
{
#ifdef DEBUG
	std::cout << "[EN] GetVerbPassiveFutureProgressive(int VerbForm = " << VerbForm << " , int VerbNum = " << VerbNum << " )" << std::endl;
#endif
	return GetVerbFutureProgressive(VerbForm,1) + " " + GetVerbPastSimple(0,VerbNum);
}

std::string en::GetVerbPassiveFuturePast(int VerbForm, int VerbNum)
{
#ifdef DEBUG
	std::cout << "[EN] GetVerbPassiveFuturePast(int VerbForm = " << VerbForm << " , int VerbNum = " << VerbNum << " )" << std::endl;
#endif
	return GetVerbFuturePast(VerbForm,1) + " " + GetVerbPastSimple(0,VerbNum);
}

std::string en::GetVerbPassiveFuturePastProgressive(int VerbForm, int VerbNum)
{
#ifdef DEBUG
	std::cout << "[EN] GetVerbPassiveFuturePastProgressive(int VerbForm = " << VerbForm << " , int VerbNum = " << VerbNum << " )" << std::endl;
#endif
	return GetVerbFuturePastProgressive(VerbForm,1) + " " + GetVerbPastSimple(0,VerbNum);
}