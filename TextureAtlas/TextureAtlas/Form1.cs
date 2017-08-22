using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Drawing.Imaging;

namespace TextureAtlas
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void groupBox2_Enter(object sender, EventArgs e)
        {

        }
        private Point firstPoint = new Point();
        private int x = 0;
        private int y = 0;

        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            this.pictureBox1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseDown);

            x = e.X;
            y = e.Y;
        }

        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            this.pictureBox1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseMove);
            if (e.Button == MouseButtons.Left)
            {
                pictureBox1.Left = (pictureBox1.Left + e.X) - x;
                pictureBox1.Top = (pictureBox1.Top + e.Y) - y;
            }
        }

        private void pictureBox1_MouseUp(object sender, MouseEventArgs e)
        {
            this.pictureBox1.MouseUp += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseUp);

            if (e.Button == MouseButtons.Left)
            {
                pictureBox1.Left = x;
                pictureBox1.Top = y;
            }
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void Save_Click(object sender, EventArgs e)
        {
            SaveFileDialog save = new SaveFileDialog();
            save.Filter = "Image files|*.png;*.jpg;*.bmp;";

            string pathDefault = Environment.CurrentDirectory;
            pathDefault = Path.GetFullPath(Path.Combine(pathDefault, @"..\"));
            if (save.ShowDialog() == DialogResult.OK)
            {
                MemoryStream ms = new MemoryStream();
                pictureBox1.Image.Save(ms, ImageFormat.Jpeg);
            }
        }

        private void Load_Click(object sender, EventArgs e)
        {
            OpenFileDialog open = new OpenFileDialog();
            open.InitialDirectory = @"C:\Users\s171102\Documents\";
            open.Filter = "Image files|*.png;*.jpg;*.bmp;";
            if (open.ShowDialog() == DialogResult.OK)
            {
                pictureBox1.Image = (Bitmap)Image.FromFile(open.FileName);
                //string text = File.ReadAllText(open.FileName);
            }
        }
    }
}
