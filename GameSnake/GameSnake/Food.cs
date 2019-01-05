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
        private int x, y, width, height;
        private SolidBrush brush;
        public Rectangle foodRec;

        public Food(Random randFood)
        {
            x = randFood.Next(0, 29) * 10;
            y = randFood.Next(0, 29) * 10;

            brush = new SolidBrush(Color.Red);

            width = 10; height = 10;

            foodRec = new Rectangle(x, y, width, height);
        }
        
        public void food_location(Random randFood)
        {
            x = randFood.Next(0, 29) * 10;
            y = randFood.Next(0, 29) * 10;
        }
        public void draw_food(Graphics game_screen)
        {
            foodRec.X = x;
            foodRec.Y = y;
            game_screen.FillEllipse(brush, foodRec);
        }
    }
}
