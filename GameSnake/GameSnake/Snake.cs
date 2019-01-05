using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Linq;
namespace GameSnake
{
    class Snake
    {
        private Rectangle[] snakeRec;
        public Rectangle[] SnakeRec
        {
            get
            {
                return snakeRec;
            }
        }
        public SolidBrush brush;
        private int x, y, width, height;


        /// <summary>
        /// hàm khởi tạo snake
        /// </summary>
        public Snake()
        {
            snakeRec = new Rectangle[3];
            brush = new SolidBrush(Color.Gray);
            x = 20;
            y = 0;
            width = 10;
            height = 10;
            for (int i = 0; i < snakeRec.Length; i++)
            {
                snakeRec[i] = new Rectangle(x, y, width, height);
                x -= 10;
            }
        }
        /// <summary>
        /// hàm vẽ snake
        /// </summary>
        /// <param name="screen"></param>
        public void Draw_snake(Graphics game_screen)
        {
            foreach (Rectangle rec in snakeRec)
            {
                game_screen.FillEllipse(brush, rec);
            }
           
        }

        /// <summary>
        /// hàm vẽ con rắn trong khi nó di chuyển
        /// </summary>
        public void Draw_snake_run()
        {
            for (int i = snakeRec.Length - 1; i > 0; i--)
            {
                snakeRec[i] = snakeRec[i - 1];
            }
        }
        public void Go_up()
        {
            Draw_snake_run();
            snakeRec[0].Y -= 10;
        }
        public void Go_down()
        {
            Draw_snake_run();
            snakeRec[0].Y += 10;
        }
        public void Turn_left()
        {
            Draw_snake_run();
            snakeRec[0].X -= 10;
        }
        public void Turn_right()
        {
            Draw_snake_run();
            snakeRec[0].X += 10;
        }
        public void snake_grow_up()
        {
            List<Rectangle> rec = snakeRec.ToList();
            rec.Add(new Rectangle(snakeRec[snakeRec.Length - 1].X, snakeRec[snakeRec.Length - 1].Y, width, height));
            snakeRec = rec.ToArray();
        }
    }
}
