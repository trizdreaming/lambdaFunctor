// lambdaFunctor.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <list>
#include <iostream>
#include <algorithm>
#include <string>

class Character
{
public:
	Character( void ) {};
	~Character( void ) {};

	void Name( std::string inputName ) { m_Name = inputName; }
	std::string getName() { return m_Name; }
	void PrintName() { std::cout << m_Name << std::endl; }

private:
	std::string m_Name;
};

// template<typename T>
// struct PrintName
// {
// 
// 	PrintName( T& inputObj ): obj( inputObj ) {};
// 	
// 	void operator()( T& obj )
// 	{
// 		obj.PrintName();
// 	}
// 	
// 	T& obj;
// };

void func( Character &obj )
{
	obj.PrintName();
}

void CharacterSortByName()
{
	std::list<Character> charList;

	Character agebreak;
	agebreak.Name( "agebreak" );
	charList.push_back( agebreak );

	Character sm9;
	sm9.Name( "sm9" );
	charList.push_back( sm9 );

	Character miku;
	miku.Name( "miku" );
	charList.push_back( miku );

	//이름 순 정렬
	charList.sort( [](Character &left, Character &right) {
		return left.getName() < right.getName();
	} );
	
	//print
	std::for_each( charList.begin(), charList.end(), func );
	//std::for_each( charList.begin(), charList.end(), PrintName<Character>(std::list<Character>::const_iter) );
// 	for ( std::list<Character>::const_iterator iter = charList.begin(); iter != charList.end(); ++iter )
// 	{
// 		auto toBeInput = iter;
// 		PrintName<Character>( &toBeInput )();
// 	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	CharacterSortByName();

	getchar();

	return 0;
}

