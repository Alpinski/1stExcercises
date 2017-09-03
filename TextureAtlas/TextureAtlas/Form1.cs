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
        /// <summary>
        /// creates a list of rectangles
        /// </summary>
		List<Rectangle> list = new List<Rectangle>();

        /// <summary>
        /// initialise the everything that needs to be
        /// </summary>
		public Form1()
		{
			InitializeComponent();
			pictureBox1.AllowDrop = true;

			this.DoubleBuffered = true;

			timer1.Interval = 100;
			timer1.Tick += new EventHandler(timer_Tick);
		}

		private Point RectStartPoint;
		private Rectangle Rect = new Rectangle();
		private Brush selectionBrush = new SolidBrush(Color.FromArgb(128, 72, 145, 220));
        private int counter = 0;
        /// <summary>
        /// what will happen when mouse button is pressed(start drawing rectangle)
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
		{
			// Determine the initial rectangle coordinates...
			RectStartPoint = e.Location;
			pictureBox1.Invalidate();
			pictureBox1.Refresh();
		}
        /// <summary>
        /// what will happen when mouse button is moved(draw rectangle)
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
		private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
		{
			if (e.Button != MouseButtons.Left)
			{
				return;
			}

			Point tempEndPoint = e.Location;
			Rect.Location = new Point(Math.Min(RectStartPoint.X, tempEndPoint.X), Math.Min(RectStartPoint.Y, tempEndPoint.Y));

			Rect.Size = new Size(Math.Abs(RectStartPoint.X - tempEndPoint.X), Math.Abs(RectStartPoint.Y - tempEndPoint.Y));

			pictureBox1.Invalidate();
			pictureBox1.Refresh();
		}

        /// <summary>
        /// paints a rectangle in the picturebox and puts it into an array
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
		private void pictureBox1_Paint(object sender, PaintEventArgs e)
		{
			// Draw the rectangle...
			if (pictureBox1.Image != null)
			{
				for (int i = 0; i < list.Count; i++)
				{
					if (listBox1.SelectedItem != null)
					{
						int value = (int)listBox1.SelectedItem;
						if (value == i)
							e.Graphics.FillRectangle(selectionBrush, list[i]);
					}
					e.Graphics.FillRectangle(selectionBrush, list[i]);
				}

				e.Graphics.FillRectangle(selectionBrush, Rect);
			}
		}
        /// <summary>
        /// when the mouse button is release it will stop drawing a rectangle
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
  		private void pictureBox1_MouseUp(object sender, MouseEventArgs e)
		{
			if (e.Button == MouseButtons.Left)
			{
				if (Rect != null && Rect.Width > 0 && Rect.Height > 0)
				{
					list.Add(Rect);
					listBox1.Items.Add(list.Count - 1);
				}
				pictureBox1.Invalidate();
				pictureBox1.Refresh();
			}
		}
        /// <summary>
        /// saves the location of the boxes you drew
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
		private void Save_Click(object sender, EventArgs e)
		{
			SaveFileDialog save = new SaveFileDialog();
			save.Filter = "Text files|*.txt";

			string pathDefault = Environment.CurrentDirectory;
			pathDefault = Path.GetFullPath(Path.Combine(pathDefault, @"..\"));
			if (save.ShowDialog() == DialogResult.OK)
			{

				using (StreamWriter file = new StreamWriter(save.FileName))
				{
					for(int i = 0; i < list.Count; ++i)
					{
						file.WriteLine(list[i].X.ToString() + "," + list[i].Y.ToString() + "," + list[i].Width.ToString() + "," + list[i].Height.ToString());
					}
				}
				
			}
		}
        /// <summary>
        /// loads your sprite sheet to be previewed
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
		private void Load_Click(object sender, EventArgs e)
		{
			OpenFileDialog open = new OpenFileDialog();
			open.InitialDirectory = @"C:\Users\s171102\Pictures";
			open.Filter = "Image files|*.png;*.jpg;*.bmp;*.tga;";
			if (open.ShowDialog() == DialogResult.OK)
			{
				pictureBox1.Image = (Bitmap)Image.FromFile(open.FileName);
				list.Clear();
				listBox1.Items.Clear();
				listBox1.Invalidate();
				listBox1.Refresh();
			}
		}
        /// <summary>
        /// refreshes the list to keep it updated
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
		private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
		{
			pictureBox1.Invalidate();
			pictureBox1.Refresh();
		}
        /// <summary>
        /// deletes a rectangle you've drawn and removes that rectangle from list
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
		private void Delete_Click(object sender, EventArgs e)
		{
		
			list.RemoveAt((int)listBox1.SelectedItem);
			
			listBox1.Items.RemoveAt((int)listBox1.SelectedItem);
			
			
			listBox1.Invalidate();
			listBox1.Refresh();

		}
        /// <summary>
        /// these next 2 functions are for dragging and dropping images onto the picturebox
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
		private void pictureBox1_DragEnter(object sender, DragEventArgs e)
		{

			e.Effect = DragDropEffects.Copy;
		}
		private void pictureBox1_DragDrop(object sender, DragEventArgs e)

		{
			foreach (string pic in ((string[])e.Data.GetData(DataFormats.FileDrop)))
			{
				Image img = Image.FromFile(pic);
				pictureBox1.Image = img;
			}
		}

        /// <summary>
        /// timer that plays the selected parts of image in the second picturebox
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
		void timer_Tick(object sender, EventArgs e)
		{
			pictureBox2.Image = ((Bitmap)pictureBox1.Image).Clone(list[counter], PixelFormat.DontCare);

			counter++;
			if(counter >= list.Count)
			{
				counter = 0;
			}
			
			pictureBox2.Refresh();
			
		}
        /// <summary>
        /// plays the selected parts when clicked
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
		private void Play_Click(object sender, EventArgs e)
		{
			 pictureBox1.Show();
			 timer1.Start();
		}
        /// <summary>
        /// loads the locations of the boxes when you reopen the tool
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
		private void button1_Click(object sender, EventArgs e)
		{
			string line;
			OpenFileDialog open = new OpenFileDialog();
			open.InitialDirectory = @"C:\Users\s171102\Pictures";
			open.Filter = "Text files|*.txt";
			if (open.ShowDialog() == DialogResult.OK)
			{
				StreamReader file = new StreamReader(open.FileName);
				while ((line = file.ReadLine()) != null)
				{
					string[] openlist = line.Split(',');
					int x = Convert.ToInt32(openlist[0]);
					int y = Convert.ToInt32(openlist[1]);
					int width = Convert.ToInt32(openlist[2]);
					int height = Convert.ToInt32(openlist[3]);
					Rectangle nRect = new Rectangle(x, y, width, height);
					list.Add(nRect);
					listBox1.Items.Add(list.Count - 1);
					pictureBox1.Refresh();
					//string line = "10,20,30,40";
					//string[] value = line.Split(',');

				}
			}
		}
        /// <summary>
        /// stops the animation preview in the picturebox2
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Stop_Click(object sender, EventArgs e)
        {
            pictureBox2.Image = null;
            timer1.Stop();
            pictureBox2.Refresh();
        }
    }
}
