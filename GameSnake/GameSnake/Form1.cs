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
        Random randFood = new Random();
        Food food;
        Graphics game_screen;

        Snake snake = new Snake();

        Boolean left = false, right = false, up = false, down = false;

        private void FGame_KeyDown(object sender, KeyEventArgs e)
        {
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
                    snake.snake_grow_up();
                    food.food_location(randFood);
                }
            }
            end_game();
            this.Invalidate();
        }

        public FGame()
        {
            InitializeComponent();
            food = new Food(randFood);
        }

        private void FGame_Click(object sender, EventArgs e)
        {
        //    SolidBrush sb = new SolidBrush(Color.Red);

        //    Graphics g = this.CreateGraphics();

        //    g.FillEllipse(sb, new Rectangle(0, 0, 10, 10));
        //    g.FillEllipse(sb, new Rectangle(10, 0, 10, 10));
        //    g.FillEllipse(sb, new Rectangle(20, 0, 10, 10));
        }

        private void FGame_Paint(object sender, PaintEventArgs e)
        {
            game_screen = e.Graphics;
            food.draw_food(game_screen);
            snake.Draw_snake(game_screen);
        }

        public void end_game()
        {
            for (int i = 1; i < snake.SnakeRec.Length; i++)
            {
                if (snake.SnakeRec[0].IntersectsWith(snake.SnakeRec[i]))
                {
                    timer1.Enabled = false;
                    MessageBox.Show("Tự cắn đuôi mà chết");
                }
            }
            if (snake.SnakeRec[0].Y < 0 || snake.SnakeRec[0].Y > 299 )
            {
                timer1.Enabled = false;
                MessageBox.Show("Đi đầu vào tường để tự sát à!  =='");
            }
            if (snake.SnakeRec[0].X < 0 || snake.SnakeRec[0].X > 299)
            {
                timer1.Enabled = false;
                MessageBox.Show("Đi đầu vào tường để tự sát à!  =='");
            }
        }
    }
}
