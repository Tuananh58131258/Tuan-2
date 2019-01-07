using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameSnake
{
    class Food
    {
        private int x, y, width, height;//biến tọa độ
        private SolidBrush brush;//biến vẽ 
        public Rectangle foodRec;//mảng tọa độ

        public Food(Random randFood)
        {
            x = randFood.Next(0, 29) * 10;//random trên khắp form
            y = randFood.Next(0, 29) * 10;

            brush = new SolidBrush(Color.Red);//định màu cho thức ăn

            width = 10; height = 10;

            foodRec = new Rectangle(x, y, width, height);//khởi tạo thức ăn mới
        }
        
        public void food_location(Random randFood)//random tọa độ thức ăn trên form
        {
            x = randFood.Next(0, 29) * 10;
            y = randFood.Next(0, 29) * 10;
        }
        public void draw_food(Graphics game_screen)//vẽ thức ăn
        {
            foodRec.X = x;
            foodRec.Y = y;
            game_screen.FillEllipse(brush, foodRec);
        }
    }
}
