﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Make_D3D11_Tool_Sample
{
    public partial class Form1 : Form
    {

        bool bRender = true;

        CLICore.Core core = null;
        
        public Form1()
        {
            InitializeComponent();

            core = new CLICore.Core();

            core.InitializeDirect3D(this.Panel_Render.Handle.ToInt32());

            Render();

        }

        private async void Render()
        {
            while(true)
            {
                core.Loop();
                await Task.Delay(10);
            }
            core.UninitializeDirect3D();
        }

        private void DrawTriangle_CheckedChanged(object sender, EventArgs e)
        {
            //실패 ㅠㅠ
            //SharpDX를 쓰는 걸로 변경
        }
    }
}
