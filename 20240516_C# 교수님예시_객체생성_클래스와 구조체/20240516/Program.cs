using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20240516
{
    enum Gender
    {
        Woman=0,
        Man
    }
    class player
    {
        //oop -> 객체지향의 특징 
        //캡슐화 은닉화 
        public string name { get; private set; }
        public Gender gender { get; private set; }
        public void Setting_name(string _name)
        {
            name = _name;
            Console.WriteLine("이름 설정 완료!");
        }
        public void Setting_gender(int i)
        {
            if(i==0)
            {
                gender = Gender.Woman;
            }
            else
            {
                gender = Gender.Man;

            }
        }
    }

    struct Player_s
    {
       public string name;
    }

    class Program
    {
        int a;//Program a라는 변수
        public static int b;//글로벌 변수
        // static void Main(string[] args)
        // 전역에서 활동하는 친구 -> 전역에서 활동하는 메서드 
        // 전역변수는 그냥 참조 가능 / 객체(class) 멤버변수는 접근할 떄 객체를 생성
        //void Main(string[] args)
        //-> Program 이라는 클래스의 메서드
        static void Main(string[] args)//전역
        {
            b = 0;//글로벌 변수 -> static main 접근 가능.

            //Program p = new Program();
            //p.a = 0;
            #region
            /*
            // c++                    c#
            //    입력 -> cin      -> console.readline 
            //    출력 -> cout  -> console.write(endl X) writeline(endl o)
             
            Console.WriteLine("안녕하세요. 월드입니다.");
            Console.Write("이름을 입력하세용 : ");
            string name = Console.ReadLine();
            Console.WriteLine(name);
            */

            //조건문 if
            //int a = 7;
            //if (a < 7)
            //{
            //    Console.WriteLine("a는 7보다 작다");
            //}
            //else if (a < 5)
            //{
            //    Console.WriteLine("a는 5보다 작다");
            //}
            //else
            //{
            //    Console.WriteLine("a는 뭔지 모르겟다");
            //}
            #endregion
            #region
            //for
            //for(int i=0;i<10;i++)
            //{
            //    Console.WriteLine("i는 "+i);
            //}

            //배열선언
            //c++
            //int array[배열크기];
            //c#
            /*
            int[] array = new int[10];

            for (int i = 0; i < 10; i++)
            {

                array[i] = i;//  기본 자료형 -> 객체? 자료형  
                Console.WriteLine(" array[i]는 " + array[i]);
            }


            player[] players = new player[10];//배열을 생성
            for (int i = 0; i < players.Length; i++)
            {
                players[i] = new player();//객체이기 떄문에 생성자 키워드를 사용
                players[i].name = Console.ReadLine();
                Console.WriteLine("  players[i].name 은" + players[i].name);
            }
            */
            /*

            int case_index = 0;
            while (true)
            {

                case_index = int.Parse(Console.ReadLine());

                switch (case_index)
                {
                    case 0:
                        Console.WriteLine("안녕 나는 정해창~");
                        break;
                    case 1:
                        Console.WriteLine("나는 먹은것 따윈 정리하지 않지");
                        break;
                    case 2:
                        Console.WriteLine("그래서 성진이가 해줬어");
                        break;
                    case 3:
                        Console.WriteLine("나는 성진이한테 커피를 사줬어");
                        break;
                    case 4:
                        Console.WriteLine("나도 치웠는데...나는 나쁜놈이...");
                        break;
                    default:
                        Console.WriteLine("전 이런 놈입니다.");
                        break;
                }
            }
            */
            #endregion
            #region
            //player player_1 = new player();//참조
            //Player_s player_s;//Value
            //
            ////int a-> 값
            //
            //player_1.name = "정해창";
            //player_s.name = "김혜린";
            //
            //Console.WriteLine(player_1.name);
            //Console.WriteLine(player_s.name);
            #endregion
            #region
            //int[] array = new int[5];
            //for(int i=0;i<array.Length;i++)
            //{
            //    array[i] = int.Parse(Console.ReadLine());
            //}
            //
            //Print_array(array);
            #endregion
            player _player = new player();
            Console.Write("닉네임을 입력해 주세요 : ");
            //Setting_name
            _player.Setting_name(Console.ReadLine());
            _player.Setting_gender(1);
            Console.WriteLine(_player.gender + " 님 환영합니다!!!");
            Console.WriteLine(_player.name + " 님 환영합니다!!!");
            Console.Write("닉네임을 변경해 주세요 : ");
            _player.Setting_name(Console.ReadLine());
            Console.WriteLine(_player.name + " 님 환영합니다!!!");

        }

        //매개변수 배열을 넣으면 그 안에 있는 배열의 인자를 출력하는 메서드 -> 전역
        public static void Print_array(int[] array)
        {

            for(int i=0;i<array.Length;i++)
            {
                Console.WriteLine(array[i]);
            }
        }


    }
}

