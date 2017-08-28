using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Drawing.Imaging;

namespace TextureAtlas
{
    public partial class Form1 : Form
    {
      //  List<Rectangle> asd;

      //Rectangle mRect;

        public Form1()
        {
            InitializeComponent();
            this.DoubleBuffered = true;
        }

        private Point RectStartPoint;
        private Rectangle Rect = new Rectangle();
        private Brush selectionBrush = new SolidBrush(Color.FromArgb(128, 72, 145, 220));

        // Start Rectangle
        //
        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            // Determine the initial rectangle coordinates...
            RectStartPoint = e.Location;
            pictureBox1.Invalidate();
            pictureBox1.Refresh();
        }

        // Draw Rectangle
        //
        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button != MouseButtons.Left)
                return;
            Point tempEndPoint = e.Location;
            Rect.Location = new Point(
                Math.Min(RectStartPoint.X, tempEndPoint.X),
                Math.Min(RectStartPoint.Y, tempEndPoint.Y));
            Rect.Size = new Size(
                Math.Abs(RectStartPoint.X - tempEndPoint.X),
                Math.Abs(RectStartPoint.Y - tempEndPoint.Y));
            pictureBox1.Invalidate();
            pictureBox1.Refresh();
        }

        // Draw Area
        //
        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            // Draw the rectangle...
            if (pictureBox1.Image != null)
            {
                if (Rect != null && Rect.Width > 0 && Rect.Height > 0)
                {
                    e.Graphics.FillRectangle(selectionBrush, Rect);
                }
            }
        }

        private void pictureBox1_MouseUp(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Right)
            {
                if (Rect.Contains(e.Location))
                {
                    Debug.WriteLine("Right click");
                }
            }
        }

        private void Save_Click(object sender, EventArgs e)
        {
            SaveFileDialog save = new SaveFileDialog();
            save.Filter = "Image files|*.png;*.jpg;*.bmp;*.tga;";

            string pathDefault = Environment.CurrentDirectory;
            pathDefault = Path.GetFullPath(Path.Combine(pathDefault, @"..\"));
            if (save.ShowDialog() == DialogResult.OK)
            {
                pictureBox1.Image.Save(save.FileName);

                MemoryStream ms = new MemoryStream();
            }
        }

        private void Load_Click(object sender, EventArgs e)
        {
            
            OpenFileDialog open = new OpenFileDialog();
            open.InitialDirectory = @"C:\Users\s171102\Pictures";
            open.Filter = "Image files|*.png;*.jpg;*.bmp;";
            if (open.ShowDialog() == DialogResult.OK)
            {
                pictureBox1.Image = (Bitmap)Image.FromFile(open.FileName);
                //string text = File.ReadAllText(open.FileName);
            }
        }
    }
}
