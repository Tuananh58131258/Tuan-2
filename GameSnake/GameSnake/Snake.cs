using System.Collections.Generic;
using System.Linq;
using System.Drawing;
namespace GameSnake
{
    class Snake
    {
        private Rectangle[] snakeRec;//khởi tạo mảng tọa độ cho rắn
        public Rectangle[] SnakeRec//tạo thuộc tính public
        {
            get
            {
                return snakeRec;
            }
        }
        public SolidBrush brush,headcolor;//khởi tạo cọ vẽ
        private int x, y, width, height;//các biến tọa độ


        /// <summary>
        /// hàm khởi tạo snake
        /// </summary>
        public Snake()
        {
            snakeRec = new Rectangle[3];
            brush = new SolidBrush(Color.Gray);//màu cho con rắn
            headcolor = new SolidBrush(Color.Blue);//màu cho phần đầu
            //tọa độ ban đầu
            x = 20;
            y = 0;
            //để con rắn hình tròn nên để width = 10 và height = 10
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
                game_screen.FillEllipse(brush, rec);//vẽ màu toàn bộ con rắn
            }
            game_screen.FillEllipse(headcolor, snakeRec[0]);//vẽ màu đầu con rắn
           
        }

        /// <summary>
        /// hàm vẽ con rắn trong khi nó di chuyển
        /// </summary>
        public void Draw_snake_run()
        {
            for (int i = snakeRec.Length - 1; i > 0; i--)
            {
                snakeRec[i] = snakeRec[i - 1];//dịch chuyển tọa độ theo đầu con rắn
            }
        }
        public void Go_up()
        {
            Draw_snake_run();
            snakeRec[0].Y -= 10;//đi lên
        }
        public void Go_down()
        {
            Draw_snake_run();
            snakeRec[0].Y += 10;//đi xuống
        }
        public void Turn_left()
        {
            Draw_snake_run();
            snakeRec[0].X -= 10;//sang trái
        }
        public void Turn_right()
        {
            Draw_snake_run();
            snakeRec[0].X += 10;//sang phải
        }
        public void snake_grow_up()//hàm con rắn lớn dần lên
        {
            List<Rectangle> rec = snakeRec.ToList();//khai báo danh sách tọa độ con rắn
            rec.Add(new Rectangle(snakeRec[snakeRec.Length - 1].X, snakeRec[snakeRec.Length - 1].Y, width, height));
            //thêm tọa độ vào
            snakeRec = rec.ToArray();//cập nhật lại con rắn
        }
    }
}
