using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GameSnake
{
    public partial class FGame : Form
    {
        int level = 1;//biến mức chơi
        int score = 0;//biến điểm số
        Random randFood = new Random();
        Food food;
        Graphics game_screen;

        Snake snake = new Snake();//khai báo rắn

        Boolean left = false, right = false, up = false, down = false;//khai báo trạng thái ban đầu

        private void FGame_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyData == Keys.Space)
            {
                timer1.Enabled = true;
                left = false; right = true; up = false; down = false;
                label1.Text = "";
            }
            //snake go up
            if (e.KeyData == Keys.Up && down == false)
            {
                up = true;
                down = false;
                left = false;
                right = false;
            }
            //snake go down
            if (e.KeyData == Keys.Down && up == false)
            {
                down = true;
                up = false;
                left = false;
                right = false;
            }
            //snake turn left
            if (e.KeyData == Keys.Left && right == false)
            {
                left = true;
                down = false;
                up = false;
                right = false;
            }
            //snake turn right
            if (e.KeyData == Keys.Right && left == false)
            {
                right = true;
                down = false;
                left = false;
                up = false;
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            toolStripStatusLabelScore.Text = score.ToString();//ép kiểu int sang string để hiển thị điểm
            toolStripStatusLabellevel.Text = level.ToString();//và mức chơi
            if (up == true)
            {
                snake.Go_up();
            }
            if (down == true)
            {
                snake.Go_down();
            }
            if (left == true)
            {
                snake.Turn_left();
            }
            if (right == true)
            {
                snake.Turn_right();
            }
            for (int i = 0; i < snake.SnakeRec.Length; i++)
            {
                if (snake.SnakeRec[i].IntersectsWith(food.foodRec))
                {
                    score += 10;//sau khi ăn 1 thức ăn thì điểm tăng lên 10
                    if (score == 100)//điểm  = 100 thì mức tăng lên 2
                    {
                        timer1.Interval = 250;
                        level = 2;
                    }
                    if (score == 200)//điểm  = 200 thì mức tăng lên 3
                    {
                        timer1.Interval = 200;
                        level = 3;
                    }
                    if (score == 300)//điểm  = 300 thì mức tăng lên 4
                    {
                        timer1.Interval = 150;
                        level = 4;
                    }
                    if (score == 400)//điểm  = 400 thì mức tăng lên 5
                    {
                        timer1.Interval = 100;
                        level = 5;
                    }
                    snake.snake_grow_up();//tăng độ dài rắn sau khi ăn
                    food.food_location(randFood);//tạo thức ăn
                }
            }
            end_game();//hà khi trò chơi kết thúc
            this.Invalidate();
        }

        public FGame()
        {
            InitializeComponent();
            food = new Food(randFood);//khơi tạo thức ăn
        }


        private void FGame_Paint(object sender, PaintEventArgs e)
        {
            //vẽ con rắn và thức ăn
            game_screen = e.Graphics;
            food.draw_food(game_screen);
            snake.Draw_snake(game_screen);
        }

        public void end_game()
        {
            //hàm kiểm tra con rắn chết
            for (int i = 1; i < snake.SnakeRec.Length; i++)
            {
                if (snake.SnakeRec[0].IntersectsWith(snake.SnakeRec[i]))//chết vì cắn đuôi
                {
                    Restart_game();
                }
            }
            if (snake.SnakeRec[0].Y < 0 || snake.SnakeRec[0].Y > 290)//chết vì đâm vào tường trái phải
            {
                Restart_game();
            }
            if (snake.SnakeRec[0].X < 0 || snake.SnakeRec[0].X > 290)//chết vì đâm vào tường trên dưới
            {
                Restart_game();
            }
        }

        public void Restart_game()
        {
            //làm sự kiến chơi lại trò chơi
            timer1.Enabled = false;
            label1.Text = "Bấm Space để bắt đầu chơi";//thông báo bắt đầu game
            //thông báo khi kết thúc game
            MessageBox.Show("Điểm của bạn là: " + score.ToString(), "Gameover!");
            score = 0;
            level = 1;
            snake = new Snake();
        }
    }
}
