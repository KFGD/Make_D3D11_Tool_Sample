﻿namespace Make_D3D11_Tool_Sample
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.Panel_Render = new System.Windows.Forms.Panel();
            this.DrawTriangle = new System.Windows.Forms.CheckBox();
            this.SuspendLayout();
            // 
            // Panel_Render
            // 
            this.Panel_Render.Location = new System.Drawing.Point(13, 13);
            this.Panel_Render.Name = "Panel_Render";
            this.Panel_Render.Size = new System.Drawing.Size(500, 500);
            this.Panel_Render.TabIndex = 0;
            // 
            // DrawTriangle
            // 
            this.DrawTriangle.AutoSize = true;
            this.DrawTriangle.Location = new System.Drawing.Point(582, 51);
            this.DrawTriangle.Name = "DrawTriangle";
            this.DrawTriangle.Size = new System.Drawing.Size(124, 19);
            this.DrawTriangle.TabIndex = 1;
            this.DrawTriangle.Text = "삼각형 그리기";
            this.DrawTriangle.UseVisualStyleBackColor = true;
            this.DrawTriangle.CheckedChanged += new System.EventHandler(this.DrawTriangle_CheckedChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(854, 528);
            this.Controls.Add(this.DrawTriangle);
            this.Controls.Add(this.Panel_Render);
            this.Name = "Form1";
            this.Text = "D3D11_SampleTool";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel Panel_Render;
        private System.Windows.Forms.CheckBox DrawTriangle;
    }
}

