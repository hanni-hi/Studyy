// 교수님과만드는숫자게임!.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

​#include <iostream>
#include "NumberGame.h"
using namespace std;
enum Operater
{
    Sum = 0,      //더하기
    Subtract,   //뺴기
    Multip,     //곱하기
    Division    //나누기
};

class Num_card//숫자카드
{
public:
    int index;
    bool isUsing;
};

class Oper_card
{
public:
    Operater oper;
    bool isUsing;
};

//메소드 분리
//카드뽑기  v
//Enum->string v
//배팅 v
//결과도출

//숫자카드뽑기-배열
int Drawing_numcard(Num_card* numcardarray)
{
    while (true)
    {
        int index = rand() % 10;
        if (numcardarray[index].isUsing)
        {
            continue;
        }
        else
        {
            numcardarray[index].isUsing = true;
            return index;
        }
    }
}


int Drawing_Oper(Oper_card* oper)
{
    while (true)
    {
        int index = rand() % 4;
        if (oper[index].isUsing)
        {
            continue;
        }
        else
        {
            oper[index].isUsing = true;
            return index;
        }
    }
}
//Enum,-> string
string Oper_toString(Operater oper)
{
    switch (oper)
    {
    case Sum:
        return "+";
    case Subtract:
        return "-";
    case Multip:
        return "X";
    case Division:
        return "/";
    default:
        return "";
    }
}
//베팅 -> 검사 10% 이상 걸엇냐?
bool betting_check(int betting_money, int player_currentMoney)
{
    if (betting_money < (player_currentMoney * 0.1))
    {
        cout << "너무적어 다시해 손모가지 나가고 싶어?" << endl;
        return false;
    }
    else if (player_currentMoney <= 0)
    {
        cout << "그지새끼니 넘어갑니다..." << endl;
        return false;
    }
    return true;
}
//결과도출
//숫자카드 2장 / 연산카드 1장 
int Result_count(Num_card* numcard, Oper_card oper, string playername)
{
    int frist_card = numcard[0].index;
    int se_card = numcard[1].index;

    int result = 0;//반환할 값
    switch (oper.oper)
    {
    case Sum:
        result = frist_card + se_card;
        break;
    case Subtract:
        result = frist_card - se_card;
        break;
    case Multip:
        result = frist_card * se_card;
        break;
    case Division:
        result = frist_card / se_card;
        break;
    }

    cout << endl;
    cout << playername << "의 값은" << frist_card << Oper_toString(oper.oper)
        << se_card << " = " << result << endl;
    cout << endl;

    return result;


}
//승이나 패냐 승패를 나누는 결과
bool Result(Num_card* player_card, Num_card* com_card,
    Oper_card Player_oper, Oper_card com_oper)
{
    int player_result = Result_count(player_card, Player_oper, "[Player]");
    int com_result = Result_count(com_card, com_oper, "[Com]");

    /*
    승리조건
      1. 7이면 무조건 승리
      2. 높은 숫자이면 높은 수를 가진 사람이 승리

    */
    if (player_result == 7 || com_result == 7)
    {
        if (player_result == 7)
        {
            return true;//이 메소드 플레이어기준
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (player_result > com_result)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}



int main()
{
    srand(time(NULL));
    Num_card numcard[10];//전체가 사용할 카드
    Num_card Player_num[2];//Player 습득한 카드
    Num_card Com_num[2];//com 습득한 카드

    Oper_card operCard[4];
    Oper_card Player_operCard;
    Oper_card Com_operCard;

    //초기 배팅 금액 
    int Player_money = 10000;
    int Com_money = 10000;

    //
    int All_betting_money = 0;//딜러~
    int Round_count = 0;//전체 라운드 카운트 
    while (true)
    {
        //카드를 초기화 -> 새로운 게임의 대한 초기화
        if (Round_count == 0)
        {
            cout << "--------------------------------------------" << endl;
            //num카드 초기화
            for (int i = 0; i < 10; i++)
            {
                numcard[i].index = i + 1;
                numcard[i].isUsing = false;
            }
            for (int i = 0; i < 4; i++)
            {
                //열거형 -> index
                operCard[i].oper = (Operater)i;
                operCard[i].isUsing = false;
            }
            All_betting_money = 0;
        }

        //라운드가 진행될때마다 카드를 분배
        if (Round_count >= 0)
        {
            //카드를 배열의 index
            int player_index = 0;
            int com_index = 0;
            //순서의 따른 카드 배분
            switch (Round_count)
            {
            case 0://첫번쨰 카드 뽑기
                cout << "첫번쨰 카드를 배분합니다....." << endl;
                player_index = Drawing_numcard(numcard);
                com_index = Drawing_numcard(numcard);
                Player_num[0] = numcard[player_index];
                Com_num[0] = numcard[com_index];
                cout << "Player가 뽑은 카드 :  " << Player_num[0].index << endl;
                break;
            case 1:
                //연산카드 배분
                cout << "연산카드를 배분합니다..." << endl;
                player_index = Drawing_Oper(operCard);
                com_index = Drawing_Oper(operCard);
                Player_operCard = operCard[player_index];
                Com_operCard = operCard[com_index];
                cout << "Player가 뽑은 연산카드 :" << Oper_toString(Player_operCard.oper) << endl;
                break;
            case 2:
                cout << "두번쨰 카드를 배분합니다....." << endl;
                player_index = Drawing_numcard(numcard);
                com_index = Drawing_numcard(numcard);
                Player_num[1] = numcard[player_index];
                Com_num[1] = numcard[com_index];
                cout << "Player가 뽑은 카드 :  " << Player_num[1].index << endl;
                break;
            case 3:
                //배팅만
                cout << "마지막 배팅을 해주세용" << endl;
                break;
            }

            //배팅작업
            int round_Betting_money = 0;
            while (true)
            {
                cout << "베팅할 금액을 입력해주세요(현재금액 : " << Player_money << ") : " << endl;
                cin >> round_Betting_money;
                if (betting_check(round_Betting_money, Player_money))
                {
                    if (Player_money > 0)
                    {
                        Player_money -= round_Betting_money;
                        Com_money -= round_Betting_money;
                        All_betting_money += (round_Betting_money * 2);//딜러니까

                    }
                    Round_count += 1;
                    break;
                }
            }

            //결과
            if (Round_count == 3)
            {
                //결과노출
                if (Result(Player_num, Com_num, Player_operCard, Com_operCard))
                {
                    //승리
                    cout << "[Player]가 승리하였습니다" << endl;
                    cout << All_betting_money << "원의 금액을 얻었습니다." << endl;
                    Player_money += All_betting_money;
                }
                else
                {
                    //패배
                    cout << "[Computer]가 승리하였습니다" << endl;
                    cout << All_betting_money << "원의 금액을 잃었습니다." << endl;
                    Com_money += All_betting_money;
                }
                Round_count = 0;
            }

            //게임종료조건
            /*
                    둘중에 한명이 모든돈을 잃었다면 게임이 종료가 된다
                    하지만 게임이 진행되고 있다면? 종료하면 안된다.
            */
            //게임종료 예외처리
            if (Round_count <= 0 && (Player_money <= 0 || Com_money <= 0))
            {
                if (Player_money <= 0)
                {
                    cout << "정말 그지가 되셨군요...꺼지세요...ㅃㅃ" << endl;
                }
                else
                {
                    cout << "컴퓨터를 파산내셨습니다....하하 ㅊㅊ" << endl;
                }
                break;
            }
        }
    }
    cout << "게임 종료" << endl;

}




