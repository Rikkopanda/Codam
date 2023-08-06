namespace Automatiseer_Systeem_App_1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.OpenPortsButton = new System.Windows.Forms.Button();
            this.StatusComLabel1 = new System.Windows.Forms.Label();
            this.StatusComLabel2 = new System.Windows.Forms.Label();
            this.StatusComLabel3 = new System.Windows.Forms.Label();
            this.RemoteArmControlLabel = new System.Windows.Forms.Label();
            this.J1AngleLabel = new System.Windows.Forms.Label();
            this.J2AngleLabel = new System.Windows.Forms.Label();
            this.J1AngleTextbox = new System.Windows.Forms.TextBox();
            this.J2AngleTextbox = new System.Windows.Forms.TextBox();
            this.Z1PositionLabel = new System.Windows.Forms.Label();
            this.Z1PositionTextBox = new System.Windows.Forms.TextBox();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.J1StuurButton = new System.Windows.Forms.Button();
            this.J2StuurButton = new System.Windows.Forms.Button();
            this.Z1StuurButton = new System.Windows.Forms.Button();
            this.DisconnectSerialsButton = new System.Windows.Forms.Button();
            this.WriteProgramLabel = new System.Windows.Forms.Label();
            this.StappenComboBox = new System.Windows.Forms.ComboBox();
            this.StapLabel = new System.Windows.Forms.Label();
            this.StapPosXLabel = new System.Windows.Forms.Label();
            this.StapPosZTextbox = new System.Windows.Forms.TextBox();
            this.StapStarttijdTextbox = new System.Windows.Forms.TextBox();
            this.StarttijdStapLabel = new System.Windows.Forms.Label();
            this.SaveStapButton = new System.Windows.Forms.Button();
            this.AantalStappenLabel = new System.Windows.Forms.Label();
            this.OutputHuidigAantalStappenLabel = new System.Windows.Forms.Label();
            this.NieuwProgrammaButton = new System.Windows.Forms.Button();
            this.ProgramShowTextBox = new System.Windows.Forms.TextBox();
            this.OpenProgramButton = new System.Windows.Forms.Button();
            this.CloseProgramButton = new System.Windows.Forms.Button();
            this.EditProgramButton = new System.Windows.Forms.Button();
            this.NewFileNameTextBox = new System.Windows.Forms.TextBox();
            this.FileNameLabel = new System.Windows.Forms.Label();
            this.SaveNewProgramButton = new System.Windows.Forms.Button();
            this.ReWriteProgramButton = new System.Windows.Forms.Button();
            this.TestSaveStapWaardeLabel = new System.Windows.Forms.Label();
            this.FileName2TextBox = new System.Windows.Forms.TextBox();
            this.FileName2Label = new System.Windows.Forms.Label();
            this.NewProgramButton = new System.Windows.Forms.Button();
            this.InverseKinematicLabel = new System.Windows.Forms.Label();
            this.DesiredPositionLabel = new System.Windows.Forms.Label();
            this.InverXTextBox = new System.Windows.Forms.TextBox();
            this.InverYTextBox = new System.Windows.Forms.TextBox();
            this.InverZTextBox = new System.Windows.Forms.TextBox();
            this.NewCalcuButton = new System.Windows.Forms.Button();
            this.CalculateButton = new System.Windows.Forms.Button();
            this.InverXLabel = new System.Windows.Forms.Label();
            this.InverYLabel = new System.Windows.Forms.Label();
            this.InverZLabel = new System.Windows.Forms.Label();
            this.SendPositionButton = new System.Windows.Forms.Button();
            this.J1Label = new System.Windows.Forms.Label();
            this.J2Label = new System.Windows.Forms.Label();
            this.ZLabel = new System.Windows.Forms.Label();
            this.J1WaardeLabel = new System.Windows.Forms.Label();
            this.J2WaardeLabel = new System.Windows.Forms.Label();
            this.ZWaardeLabel = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.TabControl = new System.Windows.Forms.TabControl();
            this.RemoteTabPage = new System.Windows.Forms.TabPage();
            this.Programma = new System.Windows.Forms.TabPage();
            this.TestSaveStapLabel = new System.Windows.Forms.Label();
            this.StapPosYTextbox = new System.Windows.Forms.TextBox();
            this.StapPosXTextbox = new System.Windows.Forms.TextBox();
            this.StapPosZLabel = new System.Windows.Forms.Label();
            this.StapPosYLabel = new System.Windows.Forms.Label();
            this.InversePosCalcuTabPage = new System.Windows.Forms.TabPage();
            this.StatusLabel = new System.Windows.Forms.Label();
            this.StatusWaardeLabel = new System.Windows.Forms.Label();
            this.TimerProgramLabel = new System.Windows.Forms.Label();
            this.ProgramTimerLabel = new System.Windows.Forms.Label();
            this.PauzeProgramLabel = new System.Windows.Forms.Label();
            this.OpenProgramButton2 = new System.Windows.Forms.Button();
            this.StartProgramButton = new System.Windows.Forms.Button();
            this.CloseProgramButton2 = new System.Windows.Forms.Button();
            this.PauzePlayButton = new System.Windows.Forms.Button();
            this.StopProgramButton = new System.Windows.Forms.Button();
            this.SerialOutputLabel = new System.Windows.Forms.Label();
            this.SerialOutputValueLabel = new System.Windows.Forms.Label();
            this.CodeInputLabel = new System.Windows.Forms.Label();
            this.CodeInputValueLabel = new System.Windows.Forms.Label();
            this.SerialtestLabel = new System.Windows.Forms.Label();
            this.ComNameLabel = new System.Windows.Forms.Label();
            this.COMselectSwitchButton = new System.Windows.Forms.Button();
            this.SerialInputTextBox = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.TabControl.SuspendLayout();
            this.RemoteTabPage.SuspendLayout();
            this.Programma.SuspendLayout();
            this.InversePosCalcuTabPage.SuspendLayout();
            this.SuspendLayout();
            // 
            // OpenPortsButton
            // 
            this.OpenPortsButton.Location = new System.Drawing.Point(12, 24);
            this.OpenPortsButton.Name = "OpenPortsButton";
            this.OpenPortsButton.Size = new System.Drawing.Size(126, 23);
            this.OpenPortsButton.TabIndex = 0;
            this.OpenPortsButton.Text = "ConnectSerials";
            this.OpenPortsButton.UseVisualStyleBackColor = true;
            this.OpenPortsButton.Click += new System.EventHandler(this.OpenPortsButton_Click);
            // 
            // StatusComLabel1
            // 
            this.StatusComLabel1.AutoSize = true;
            this.StatusComLabel1.Location = new System.Drawing.Point(9, 74);
            this.StatusComLabel1.Name = "StatusComLabel1";
            this.StatusComLabel1.Size = new System.Drawing.Size(74, 13);
            this.StatusComLabel1.TabIndex = 1;
            this.StatusComLabel1.Text = "COMSTATUS";
            // 
            // StatusComLabel2
            // 
            this.StatusComLabel2.AutoSize = true;
            this.StatusComLabel2.Location = new System.Drawing.Point(9, 98);
            this.StatusComLabel2.Name = "StatusComLabel2";
            this.StatusComLabel2.Size = new System.Drawing.Size(74, 13);
            this.StatusComLabel2.TabIndex = 2;
            this.StatusComLabel2.Text = "COMSTATUS";
            // 
            // StatusComLabel3
            // 
            this.StatusComLabel3.AutoSize = true;
            this.StatusComLabel3.Location = new System.Drawing.Point(9, 120);
            this.StatusComLabel3.Name = "StatusComLabel3";
            this.StatusComLabel3.Size = new System.Drawing.Size(74, 13);
            this.StatusComLabel3.TabIndex = 3;
            this.StatusComLabel3.Text = "COMSTATUS";
            // 
            // RemoteArmControlLabel
            // 
            this.RemoteArmControlLabel.AutoSize = true;
            this.RemoteArmControlLabel.Location = new System.Drawing.Point(10, 29);
            this.RemoteArmControlLabel.Name = "RemoteArmControlLabel";
            this.RemoteArmControlLabel.Size = new System.Drawing.Size(95, 13);
            this.RemoteArmControlLabel.TabIndex = 4;
            this.RemoteArmControlLabel.Text = "ArmControlRemote";
            // 
            // J1AngleLabel
            // 
            this.J1AngleLabel.AutoSize = true;
            this.J1AngleLabel.Location = new System.Drawing.Point(10, 57);
            this.J1AngleLabel.Name = "J1AngleLabel";
            this.J1AngleLabel.Size = new System.Drawing.Size(51, 13);
            this.J1AngleLabel.TabIndex = 5;
            this.J1AngleLabel.Text = "J1 Angle:";
            // 
            // J2AngleLabel
            // 
            this.J2AngleLabel.AutoSize = true;
            this.J2AngleLabel.Location = new System.Drawing.Point(10, 114);
            this.J2AngleLabel.Name = "J2AngleLabel";
            this.J2AngleLabel.Size = new System.Drawing.Size(51, 13);
            this.J2AngleLabel.TabIndex = 6;
            this.J2AngleLabel.Text = "J2 Angle:";
            // 
            // J1AngleTextbox
            // 
            this.J1AngleTextbox.Location = new System.Drawing.Point(13, 84);
            this.J1AngleTextbox.Name = "J1AngleTextbox";
            this.J1AngleTextbox.Size = new System.Drawing.Size(100, 20);
            this.J1AngleTextbox.TabIndex = 7;
            // 
            // J2AngleTextbox
            // 
            this.J2AngleTextbox.Location = new System.Drawing.Point(13, 142);
            this.J2AngleTextbox.Name = "J2AngleTextbox";
            this.J2AngleTextbox.Size = new System.Drawing.Size(100, 20);
            this.J2AngleTextbox.TabIndex = 8;
            // 
            // Z1PositionLabel
            // 
            this.Z1PositionLabel.AutoSize = true;
            this.Z1PositionLabel.Location = new System.Drawing.Point(10, 182);
            this.Z1PositionLabel.Name = "Z1PositionLabel";
            this.Z1PositionLabel.Size = new System.Drawing.Size(60, 13);
            this.Z1PositionLabel.TabIndex = 9;
            this.Z1PositionLabel.Text = "Z1 Position";
            // 
            // Z1PositionTextBox
            // 
            this.Z1PositionTextBox.Location = new System.Drawing.Point(13, 209);
            this.Z1PositionTextBox.Name = "Z1PositionTextBox";
            this.Z1PositionTextBox.Size = new System.Drawing.Size(100, 20);
            this.Z1PositionTextBox.TabIndex = 10;
            // 
            // J1StuurButton
            // 
            this.J1StuurButton.Location = new System.Drawing.Point(119, 81);
            this.J1StuurButton.Name = "J1StuurButton";
            this.J1StuurButton.Size = new System.Drawing.Size(39, 23);
            this.J1StuurButton.TabIndex = 11;
            this.J1StuurButton.Text = "send";
            this.J1StuurButton.UseVisualStyleBackColor = true;
            this.J1StuurButton.Click += new System.EventHandler(this.J1StuurButton_Click);
            // 
            // J2StuurButton
            // 
            this.J2StuurButton.Location = new System.Drawing.Point(119, 140);
            this.J2StuurButton.Name = "J2StuurButton";
            this.J2StuurButton.Size = new System.Drawing.Size(39, 23);
            this.J2StuurButton.TabIndex = 12;
            this.J2StuurButton.Text = "send";
            this.J2StuurButton.UseVisualStyleBackColor = true;
            this.J2StuurButton.Click += new System.EventHandler(this.J2StuurButton_Click);
            // 
            // Z1StuurButton
            // 
            this.Z1StuurButton.Location = new System.Drawing.Point(119, 206);
            this.Z1StuurButton.Name = "Z1StuurButton";
            this.Z1StuurButton.Size = new System.Drawing.Size(39, 23);
            this.Z1StuurButton.TabIndex = 13;
            this.Z1StuurButton.Text = "send";
            this.Z1StuurButton.UseVisualStyleBackColor = true;
            this.Z1StuurButton.Click += new System.EventHandler(this.Z1StuurButton_Click);
            // 
            // DisconnectSerialsButton
            // 
            this.DisconnectSerialsButton.Location = new System.Drawing.Point(12, 48);
            this.DisconnectSerialsButton.Name = "DisconnectSerialsButton";
            this.DisconnectSerialsButton.Size = new System.Drawing.Size(126, 23);
            this.DisconnectSerialsButton.TabIndex = 14;
            this.DisconnectSerialsButton.Text = "DisconnectSerials";
            this.DisconnectSerialsButton.UseVisualStyleBackColor = true;
            this.DisconnectSerialsButton.Click += new System.EventHandler(this.DisconnectSerialsButton_Click);
            // 
            // WriteProgramLabel
            // 
            this.WriteProgramLabel.AutoSize = true;
            this.WriteProgramLabel.Location = new System.Drawing.Point(19, 5);
            this.WriteProgramLabel.Name = "WriteProgramLabel";
            this.WriteProgramLabel.Size = new System.Drawing.Size(74, 13);
            this.WriteProgramLabel.TabIndex = 15;
            this.WriteProgramLabel.Text = "Write Program";
            // 
            // StappenComboBox
            // 
            this.StappenComboBox.Enabled = false;
            this.StappenComboBox.FormattingEnabled = true;
            this.StappenComboBox.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10",
            "11"});
            this.StappenComboBox.Location = new System.Drawing.Point(22, 111);
            this.StappenComboBox.Name = "StappenComboBox";
            this.StappenComboBox.Size = new System.Drawing.Size(121, 21);
            this.StappenComboBox.TabIndex = 16;
            this.StappenComboBox.SelectedIndexChanged += new System.EventHandler(this.StappenComboBox_SelectedIndexChanged);
            // 
            // StapLabel
            // 
            this.StapLabel.AutoSize = true;
            this.StapLabel.Location = new System.Drawing.Point(19, 95);
            this.StapLabel.Name = "StapLabel";
            this.StapLabel.Size = new System.Drawing.Size(32, 13);
            this.StapLabel.TabIndex = 17;
            this.StapLabel.Text = "Stap:";
            // 
            // StapPosXLabel
            // 
            this.StapPosXLabel.AutoSize = true;
            this.StapPosXLabel.Location = new System.Drawing.Point(21, 137);
            this.StapPosXLabel.Name = "StapPosXLabel";
            this.StapPosXLabel.Size = new System.Drawing.Size(51, 13);
            this.StapPosXLabel.TabIndex = 18;
            this.StapPosXLabel.Text = "Positie X:";
            // 
            // StapPosZTextbox
            // 
            this.StapPosZTextbox.Enabled = false;
            this.StapPosZTextbox.Location = new System.Drawing.Point(22, 233);
            this.StapPosZTextbox.Name = "StapPosZTextbox";
            this.StapPosZTextbox.Size = new System.Drawing.Size(121, 20);
            this.StapPosZTextbox.TabIndex = 19;
            // 
            // StapStarttijdTextbox
            // 
            this.StapStarttijdTextbox.Enabled = false;
            this.StapStarttijdTextbox.Location = new System.Drawing.Point(22, 271);
            this.StapStarttijdTextbox.Name = "StapStarttijdTextbox";
            this.StapStarttijdTextbox.Size = new System.Drawing.Size(121, 20);
            this.StapStarttijdTextbox.TabIndex = 21;
            // 
            // StarttijdStapLabel
            // 
            this.StarttijdStapLabel.AutoSize = true;
            this.StarttijdStapLabel.Location = new System.Drawing.Point(19, 256);
            this.StarttijdStapLabel.Name = "StarttijdStapLabel";
            this.StarttijdStapLabel.Size = new System.Drawing.Size(56, 13);
            this.StarttijdStapLabel.TabIndex = 20;
            this.StarttijdStapLabel.Text = "Starttijd(s):";
            // 
            // SaveStapButton
            // 
            this.SaveStapButton.Enabled = false;
            this.SaveStapButton.Location = new System.Drawing.Point(149, 268);
            this.SaveStapButton.Name = "SaveStapButton";
            this.SaveStapButton.Size = new System.Drawing.Size(83, 26);
            this.SaveStapButton.TabIndex = 22;
            this.SaveStapButton.Text = "SaveStap";
            this.SaveStapButton.UseVisualStyleBackColor = true;
            this.SaveStapButton.Click += new System.EventHandler(this.SaveStapButton_Click);
            // 
            // AantalStappenLabel
            // 
            this.AantalStappenLabel.AutoSize = true;
            this.AantalStappenLabel.Location = new System.Drawing.Point(30, 305);
            this.AantalStappenLabel.Name = "AantalStappenLabel";
            this.AantalStappenLabel.Size = new System.Drawing.Size(113, 13);
            this.AantalStappenLabel.TabIndex = 23;
            this.AantalStappenLabel.Text = "Huidig aantal stappen:";
            // 
            // OutputHuidigAantalStappenLabel
            // 
            this.OutputHuidigAantalStappenLabel.AutoSize = true;
            this.OutputHuidigAantalStappenLabel.Location = new System.Drawing.Point(149, 305);
            this.OutputHuidigAantalStappenLabel.Name = "OutputHuidigAantalStappenLabel";
            this.OutputHuidigAantalStappenLabel.Size = new System.Drawing.Size(38, 13);
            this.OutputHuidigAantalStappenLabel.TabIndex = 24;
            this.OutputHuidigAantalStappenLabel.Text = "Stap 0";
            // 
            // NieuwProgrammaButton
            // 
            this.NieuwProgrammaButton.Location = new System.Drawing.Point(22, 21);
            this.NieuwProgrammaButton.Name = "NieuwProgrammaButton";
            this.NieuwProgrammaButton.Size = new System.Drawing.Size(121, 26);
            this.NieuwProgrammaButton.TabIndex = 25;
            this.NieuwProgrammaButton.Text = "Nieuw programma";
            this.NieuwProgrammaButton.UseVisualStyleBackColor = true;
            this.NieuwProgrammaButton.Click += new System.EventHandler(this.NieuwProgrammaButton_Click);
            // 
            // ProgramShowTextBox
            // 
            this.ProgramShowTextBox.Enabled = false;
            this.ProgramShowTextBox.Location = new System.Drawing.Point(518, 108);
            this.ProgramShowTextBox.Multiline = true;
            this.ProgramShowTextBox.Name = "ProgramShowTextBox";
            this.ProgramShowTextBox.ReadOnly = true;
            this.ProgramShowTextBox.Size = new System.Drawing.Size(98, 151);
            this.ProgramShowTextBox.TabIndex = 26;
            // 
            // OpenProgramButton
            // 
            this.OpenProgramButton.Location = new System.Drawing.Point(414, 169);
            this.OpenProgramButton.Name = "OpenProgramButton";
            this.OpenProgramButton.Size = new System.Drawing.Size(98, 26);
            this.OpenProgramButton.TabIndex = 27;
            this.OpenProgramButton.Text = "Open Program";
            this.OpenProgramButton.UseVisualStyleBackColor = true;
            this.OpenProgramButton.Click += new System.EventHandler(this.OpenProgramButton_Click);
            // 
            // CloseProgramButton
            // 
            this.CloseProgramButton.Location = new System.Drawing.Point(414, 201);
            this.CloseProgramButton.Name = "CloseProgramButton";
            this.CloseProgramButton.Size = new System.Drawing.Size(98, 26);
            this.CloseProgramButton.TabIndex = 28;
            this.CloseProgramButton.Text = "Close Program";
            this.CloseProgramButton.UseVisualStyleBackColor = true;
            this.CloseProgramButton.Click += new System.EventHandler(this.CloseProgramButton_Click);
            // 
            // EditProgramButton
            // 
            this.EditProgramButton.Location = new System.Drawing.Point(414, 233);
            this.EditProgramButton.Name = "EditProgramButton";
            this.EditProgramButton.Size = new System.Drawing.Size(98, 26);
            this.EditProgramButton.TabIndex = 29;
            this.EditProgramButton.Text = "Edit Program";
            this.EditProgramButton.UseVisualStyleBackColor = true;
            this.EditProgramButton.Click += new System.EventHandler(this.EditProgramButton_Click);
            // 
            // NewFileNameTextBox
            // 
            this.NewFileNameTextBox.Enabled = false;
            this.NewFileNameTextBox.Location = new System.Drawing.Point(22, 71);
            this.NewFileNameTextBox.Name = "NewFileNameTextBox";
            this.NewFileNameTextBox.Size = new System.Drawing.Size(121, 20);
            this.NewFileNameTextBox.TabIndex = 30;
            // 
            // FileNameLabel
            // 
            this.FileNameLabel.AutoSize = true;
            this.FileNameLabel.Location = new System.Drawing.Point(19, 50);
            this.FileNameLabel.Name = "FileNameLabel";
            this.FileNameLabel.Size = new System.Drawing.Size(54, 13);
            this.FileNameLabel.TabIndex = 31;
            this.FileNameLabel.Text = "FileName:";
            // 
            // SaveNewProgramButton
            // 
            this.SaveNewProgramButton.Enabled = false;
            this.SaveNewProgramButton.Location = new System.Drawing.Point(144, 21);
            this.SaveNewProgramButton.Name = "SaveNewProgramButton";
            this.SaveNewProgramButton.Size = new System.Drawing.Size(121, 26);
            this.SaveNewProgramButton.TabIndex = 32;
            this.SaveNewProgramButton.Text = "Save New Program";
            this.SaveNewProgramButton.UseVisualStyleBackColor = true;
            this.SaveNewProgramButton.Click += new System.EventHandler(this.SaveNewProgramButton_Click);
            // 
            // ReWriteProgramButton
            // 
            this.ReWriteProgramButton.Location = new System.Drawing.Point(414, 265);
            this.ReWriteProgramButton.Name = "ReWriteProgramButton";
            this.ReWriteProgramButton.Size = new System.Drawing.Size(98, 26);
            this.ReWriteProgramButton.TabIndex = 33;
            this.ReWriteProgramButton.Text = "Rewrite Program";
            this.ReWriteProgramButton.UseVisualStyleBackColor = true;
            this.ReWriteProgramButton.Click += new System.EventHandler(this.ReWriteProgramButton_Click);
            // 
            // TestSaveStapWaardeLabel
            // 
            this.TestSaveStapWaardeLabel.AutoSize = true;
            this.TestSaveStapWaardeLabel.Location = new System.Drawing.Point(155, 95);
            this.TestSaveStapWaardeLabel.Name = "TestSaveStapWaardeLabel";
            this.TestSaveStapWaardeLabel.Size = new System.Drawing.Size(19, 13);
            this.TestSaveStapWaardeLabel.TabIndex = 34;
            this.TestSaveStapWaardeLabel.Text = "----";
            // 
            // FileName2TextBox
            // 
            this.FileName2TextBox.Enabled = false;
            this.FileName2TextBox.Location = new System.Drawing.Point(414, 111);
            this.FileName2TextBox.Name = "FileName2TextBox";
            this.FileName2TextBox.ReadOnly = true;
            this.FileName2TextBox.Size = new System.Drawing.Size(97, 20);
            this.FileName2TextBox.TabIndex = 35;
            // 
            // FileName2Label
            // 
            this.FileName2Label.AutoSize = true;
            this.FileName2Label.Location = new System.Drawing.Point(411, 94);
            this.FileName2Label.Name = "FileName2Label";
            this.FileName2Label.Size = new System.Drawing.Size(54, 13);
            this.FileName2Label.TabIndex = 36;
            this.FileName2Label.Text = "FileName:";
            // 
            // NewProgramButton
            // 
            this.NewProgramButton.Location = new System.Drawing.Point(414, 137);
            this.NewProgramButton.Name = "NewProgramButton";
            this.NewProgramButton.Size = new System.Drawing.Size(98, 26);
            this.NewProgramButton.TabIndex = 37;
            this.NewProgramButton.Text = "New Program";
            this.NewProgramButton.UseVisualStyleBackColor = true;
            this.NewProgramButton.Click += new System.EventHandler(this.NewProgramButton_Click);
            // 
            // InverseKinematicLabel
            // 
            this.InverseKinematicLabel.AutoSize = true;
            this.InverseKinematicLabel.Location = new System.Drawing.Point(100, 5);
            this.InverseKinematicLabel.Name = "InverseKinematicLabel";
            this.InverseKinematicLabel.Size = new System.Drawing.Size(88, 13);
            this.InverseKinematicLabel.TabIndex = 38;
            this.InverseKinematicLabel.Text = "InverseKinamatic";
            // 
            // DesiredPositionLabel
            // 
            this.DesiredPositionLabel.AutoSize = true;
            this.DesiredPositionLabel.Location = new System.Drawing.Point(100, 29);
            this.DesiredPositionLabel.Name = "DesiredPositionLabel";
            this.DesiredPositionLabel.Size = new System.Drawing.Size(168, 13);
            this.DesiredPositionLabel.TabIndex = 39;
            this.DesiredPositionLabel.Text = "Desired Position: X--- Y--- Z--- (mm)";
            // 
            // InverXTextBox
            // 
            this.InverXTextBox.Enabled = false;
            this.InverXTextBox.Location = new System.Drawing.Point(103, 48);
            this.InverXTextBox.Name = "InverXTextBox";
            this.InverXTextBox.Size = new System.Drawing.Size(165, 20);
            this.InverXTextBox.TabIndex = 40;
            // 
            // InverYTextBox
            // 
            this.InverYTextBox.Enabled = false;
            this.InverYTextBox.Location = new System.Drawing.Point(103, 72);
            this.InverYTextBox.Name = "InverYTextBox";
            this.InverYTextBox.Size = new System.Drawing.Size(165, 20);
            this.InverYTextBox.TabIndex = 41;
            // 
            // InverZTextBox
            // 
            this.InverZTextBox.Enabled = false;
            this.InverZTextBox.Location = new System.Drawing.Point(103, 98);
            this.InverZTextBox.Name = "InverZTextBox";
            this.InverZTextBox.Size = new System.Drawing.Size(165, 20);
            this.InverZTextBox.TabIndex = 42;
            // 
            // NewCalcuButton
            // 
            this.NewCalcuButton.Location = new System.Drawing.Point(33, 3);
            this.NewCalcuButton.Name = "NewCalcuButton";
            this.NewCalcuButton.Size = new System.Drawing.Size(67, 26);
            this.NewCalcuButton.TabIndex = 44;
            this.NewCalcuButton.Text = "NewCalcu";
            this.NewCalcuButton.UseVisualStyleBackColor = true;
            this.NewCalcuButton.Click += new System.EventHandler(this.NewCalcuButton_Click);
            // 
            // CalculateButton
            // 
            this.CalculateButton.Location = new System.Drawing.Point(33, 123);
            this.CalculateButton.Name = "CalculateButton";
            this.CalculateButton.Size = new System.Drawing.Size(67, 25);
            this.CalculateButton.TabIndex = 45;
            this.CalculateButton.Text = "Calculate";
            this.CalculateButton.UseVisualStyleBackColor = true;
            this.CalculateButton.Click += new System.EventHandler(this.CalculateButton_Click);
            // 
            // InverXLabel
            // 
            this.InverXLabel.AutoSize = true;
            this.InverXLabel.Location = new System.Drawing.Point(64, 51);
            this.InverXLabel.Name = "InverXLabel";
            this.InverXLabel.Size = new System.Drawing.Size(14, 13);
            this.InverXLabel.TabIndex = 46;
            this.InverXLabel.Text = "X";
            // 
            // InverYLabel
            // 
            this.InverYLabel.AutoSize = true;
            this.InverYLabel.Location = new System.Drawing.Point(64, 75);
            this.InverYLabel.Name = "InverYLabel";
            this.InverYLabel.Size = new System.Drawing.Size(14, 13);
            this.InverYLabel.TabIndex = 47;
            this.InverYLabel.Text = "Y";
            // 
            // InverZLabel
            // 
            this.InverZLabel.AutoSize = true;
            this.InverZLabel.Location = new System.Drawing.Point(64, 101);
            this.InverZLabel.Name = "InverZLabel";
            this.InverZLabel.Size = new System.Drawing.Size(14, 13);
            this.InverZLabel.TabIndex = 48;
            this.InverZLabel.Text = "Z";
            // 
            // SendPositionButton
            // 
            this.SendPositionButton.Location = new System.Drawing.Point(15, 152);
            this.SendPositionButton.Name = "SendPositionButton";
            this.SendPositionButton.Size = new System.Drawing.Size(85, 25);
            this.SendPositionButton.TabIndex = 49;
            this.SendPositionButton.Text = "Send Position";
            this.SendPositionButton.UseVisualStyleBackColor = true;
            this.SendPositionButton.Click += new System.EventHandler(this.SendPositionButton_Click);
            // 
            // J1Label
            // 
            this.J1Label.AutoSize = true;
            this.J1Label.Location = new System.Drawing.Point(106, 129);
            this.J1Label.Name = "J1Label";
            this.J1Label.Size = new System.Drawing.Size(21, 13);
            this.J1Label.TabIndex = 50;
            this.J1Label.Text = "J1:";
            // 
            // J2Label
            // 
            this.J2Label.AutoSize = true;
            this.J2Label.Location = new System.Drawing.Point(106, 152);
            this.J2Label.Name = "J2Label";
            this.J2Label.Size = new System.Drawing.Size(21, 13);
            this.J2Label.TabIndex = 51;
            this.J2Label.Text = "J2:";
            // 
            // ZLabel
            // 
            this.ZLabel.AutoSize = true;
            this.ZLabel.Location = new System.Drawing.Point(106, 174);
            this.ZLabel.Name = "ZLabel";
            this.ZLabel.Size = new System.Drawing.Size(17, 13);
            this.ZLabel.TabIndex = 52;
            this.ZLabel.Text = "Z:";
            // 
            // J1WaardeLabel
            // 
            this.J1WaardeLabel.AutoSize = true;
            this.J1WaardeLabel.Location = new System.Drawing.Point(131, 130);
            this.J1WaardeLabel.Name = "J1WaardeLabel";
            this.J1WaardeLabel.Size = new System.Drawing.Size(16, 13);
            this.J1WaardeLabel.TabIndex = 53;
            this.J1WaardeLabel.Text = "---";
            // 
            // J2WaardeLabel
            // 
            this.J2WaardeLabel.AutoSize = true;
            this.J2WaardeLabel.Location = new System.Drawing.Point(131, 152);
            this.J2WaardeLabel.Name = "J2WaardeLabel";
            this.J2WaardeLabel.Size = new System.Drawing.Size(16, 13);
            this.J2WaardeLabel.TabIndex = 54;
            this.J2WaardeLabel.Text = "---";
            // 
            // ZWaardeLabel
            // 
            this.ZWaardeLabel.AutoSize = true;
            this.ZWaardeLabel.Location = new System.Drawing.Point(131, 174);
            this.ZWaardeLabel.Name = "ZWaardeLabel";
            this.ZWaardeLabel.Size = new System.Drawing.Size(16, 13);
            this.ZWaardeLabel.TabIndex = 55;
            this.ZWaardeLabel.Text = "---";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::Automatiseer_Systeem_App_1.Properties.Resources.Foto_Bereik2;
            this.pictureBox1.Location = new System.Drawing.Point(274, 6);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(391, 324);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 56;
            this.pictureBox1.TabStop = false;
            // 
            // TabControl
            // 
            this.TabControl.Controls.Add(this.RemoteTabPage);
            this.TabControl.Controls.Add(this.Programma);
            this.TabControl.Controls.Add(this.InversePosCalcuTabPage);
            this.TabControl.Location = new System.Drawing.Point(12, 146);
            this.TabControl.Name = "TabControl";
            this.TabControl.SelectedIndex = 0;
            this.TabControl.Size = new System.Drawing.Size(679, 363);
            this.TabControl.TabIndex = 57;
            // 
            // RemoteTabPage
            // 
            this.RemoteTabPage.Controls.Add(this.RemoteArmControlLabel);
            this.RemoteTabPage.Controls.Add(this.J1AngleLabel);
            this.RemoteTabPage.Controls.Add(this.J2AngleLabel);
            this.RemoteTabPage.Controls.Add(this.J1AngleTextbox);
            this.RemoteTabPage.Controls.Add(this.J2AngleTextbox);
            this.RemoteTabPage.Controls.Add(this.Z1PositionLabel);
            this.RemoteTabPage.Controls.Add(this.Z1PositionTextBox);
            this.RemoteTabPage.Controls.Add(this.J1StuurButton);
            this.RemoteTabPage.Controls.Add(this.J2StuurButton);
            this.RemoteTabPage.Controls.Add(this.Z1StuurButton);
            this.RemoteTabPage.Location = new System.Drawing.Point(4, 22);
            this.RemoteTabPage.Name = "RemoteTabPage";
            this.RemoteTabPage.Size = new System.Drawing.Size(671, 337);
            this.RemoteTabPage.TabIndex = 2;
            this.RemoteTabPage.Text = "Remote";
            this.RemoteTabPage.UseVisualStyleBackColor = true;
            // 
            // Programma
            // 
            this.Programma.Controls.Add(this.TestSaveStapLabel);
            this.Programma.Controls.Add(this.StapPosYTextbox);
            this.Programma.Controls.Add(this.StapPosXTextbox);
            this.Programma.Controls.Add(this.StapPosZLabel);
            this.Programma.Controls.Add(this.StapPosYLabel);
            this.Programma.Controls.Add(this.WriteProgramLabel);
            this.Programma.Controls.Add(this.FileName2Label);
            this.Programma.Controls.Add(this.NewProgramButton);
            this.Programma.Controls.Add(this.StappenComboBox);
            this.Programma.Controls.Add(this.StapLabel);
            this.Programma.Controls.Add(this.FileName2TextBox);
            this.Programma.Controls.Add(this.ReWriteProgramButton);
            this.Programma.Controls.Add(this.StapPosXLabel);
            this.Programma.Controls.Add(this.EditProgramButton);
            this.Programma.Controls.Add(this.TestSaveStapWaardeLabel);
            this.Programma.Controls.Add(this.CloseProgramButton);
            this.Programma.Controls.Add(this.StapPosZTextbox);
            this.Programma.Controls.Add(this.OpenProgramButton);
            this.Programma.Controls.Add(this.StarttijdStapLabel);
            this.Programma.Controls.Add(this.ProgramShowTextBox);
            this.Programma.Controls.Add(this.SaveNewProgramButton);
            this.Programma.Controls.Add(this.StapStarttijdTextbox);
            this.Programma.Controls.Add(this.FileNameLabel);
            this.Programma.Controls.Add(this.SaveStapButton);
            this.Programma.Controls.Add(this.NewFileNameTextBox);
            this.Programma.Controls.Add(this.AantalStappenLabel);
            this.Programma.Controls.Add(this.OutputHuidigAantalStappenLabel);
            this.Programma.Controls.Add(this.NieuwProgrammaButton);
            this.Programma.Location = new System.Drawing.Point(4, 22);
            this.Programma.Name = "Programma";
            this.Programma.Padding = new System.Windows.Forms.Padding(3);
            this.Programma.Size = new System.Drawing.Size(671, 337);
            this.Programma.TabIndex = 0;
            this.Programma.Text = "Programma";
            this.Programma.UseVisualStyleBackColor = true;
            // 
            // TestSaveStapLabel
            // 
            this.TestSaveStapLabel.AutoSize = true;
            this.TestSaveStapLabel.Location = new System.Drawing.Point(155, 71);
            this.TestSaveStapLabel.Name = "TestSaveStapLabel";
            this.TestSaveStapLabel.Size = new System.Drawing.Size(196, 13);
            this.TestSaveStapLabel.TabIndex = 43;
            this.TestSaveStapLabel.Text = "Wat gesaved? +Inverse joints gerekend";
            // 
            // StapPosYTextbox
            // 
            this.StapPosYTextbox.Enabled = false;
            this.StapPosYTextbox.Location = new System.Drawing.Point(22, 192);
            this.StapPosYTextbox.Name = "StapPosYTextbox";
            this.StapPosYTextbox.Size = new System.Drawing.Size(121, 20);
            this.StapPosYTextbox.TabIndex = 42;
            // 
            // StapPosXTextbox
            // 
            this.StapPosXTextbox.Enabled = false;
            this.StapPosXTextbox.Location = new System.Drawing.Point(22, 153);
            this.StapPosXTextbox.Name = "StapPosXTextbox";
            this.StapPosXTextbox.Size = new System.Drawing.Size(121, 20);
            this.StapPosXTextbox.TabIndex = 41;
            // 
            // StapPosZLabel
            // 
            this.StapPosZLabel.AutoSize = true;
            this.StapPosZLabel.Location = new System.Drawing.Point(21, 214);
            this.StapPosZLabel.Name = "StapPosZLabel";
            this.StapPosZLabel.Size = new System.Drawing.Size(51, 13);
            this.StapPosZLabel.TabIndex = 40;
            this.StapPosZLabel.Text = "Positie Z:";
            // 
            // StapPosYLabel
            // 
            this.StapPosYLabel.AutoSize = true;
            this.StapPosYLabel.Location = new System.Drawing.Point(21, 176);
            this.StapPosYLabel.Name = "StapPosYLabel";
            this.StapPosYLabel.Size = new System.Drawing.Size(51, 13);
            this.StapPosYLabel.TabIndex = 39;
            this.StapPosYLabel.Text = "Positie Y:";
            // 
            // InversePosCalcuTabPage
            // 
            this.InversePosCalcuTabPage.Controls.Add(this.NewCalcuButton);
            this.InversePosCalcuTabPage.Controls.Add(this.pictureBox1);
            this.InversePosCalcuTabPage.Controls.Add(this.InverseKinematicLabel);
            this.InversePosCalcuTabPage.Controls.Add(this.ZWaardeLabel);
            this.InversePosCalcuTabPage.Controls.Add(this.DesiredPositionLabel);
            this.InversePosCalcuTabPage.Controls.Add(this.J2WaardeLabel);
            this.InversePosCalcuTabPage.Controls.Add(this.InverXTextBox);
            this.InversePosCalcuTabPage.Controls.Add(this.J1WaardeLabel);
            this.InversePosCalcuTabPage.Controls.Add(this.InverYTextBox);
            this.InversePosCalcuTabPage.Controls.Add(this.ZLabel);
            this.InversePosCalcuTabPage.Controls.Add(this.InverZTextBox);
            this.InversePosCalcuTabPage.Controls.Add(this.J2Label);
            this.InversePosCalcuTabPage.Controls.Add(this.CalculateButton);
            this.InversePosCalcuTabPage.Controls.Add(this.J1Label);
            this.InversePosCalcuTabPage.Controls.Add(this.InverXLabel);
            this.InversePosCalcuTabPage.Controls.Add(this.SendPositionButton);
            this.InversePosCalcuTabPage.Controls.Add(this.InverYLabel);
            this.InversePosCalcuTabPage.Controls.Add(this.InverZLabel);
            this.InversePosCalcuTabPage.Location = new System.Drawing.Point(4, 22);
            this.InversePosCalcuTabPage.Name = "InversePosCalcuTabPage";
            this.InversePosCalcuTabPage.Padding = new System.Windows.Forms.Padding(3);
            this.InversePosCalcuTabPage.Size = new System.Drawing.Size(671, 337);
            this.InversePosCalcuTabPage.TabIndex = 1;
            this.InversePosCalcuTabPage.Text = "InversePosCalcu";
            this.InversePosCalcuTabPage.UseVisualStyleBackColor = true;
            // 
            // StatusLabel
            // 
            this.StatusLabel.AutoSize = true;
            this.StatusLabel.Location = new System.Drawing.Point(618, 9);
            this.StatusLabel.Name = "StatusLabel";
            this.StatusLabel.Size = new System.Drawing.Size(40, 13);
            this.StatusLabel.TabIndex = 58;
            this.StatusLabel.Text = "Status:";
            // 
            // StatusWaardeLabel
            // 
            this.StatusWaardeLabel.AutoSize = true;
            this.StatusWaardeLabel.Location = new System.Drawing.Point(618, 29);
            this.StatusWaardeLabel.Name = "StatusWaardeLabel";
            this.StatusWaardeLabel.Size = new System.Drawing.Size(19, 13);
            this.StatusWaardeLabel.TabIndex = 59;
            this.StatusWaardeLabel.Text = "----";
            // 
            // TimerProgramLabel
            // 
            this.TimerProgramLabel.AutoSize = true;
            this.TimerProgramLabel.Location = new System.Drawing.Point(463, 9);
            this.TimerProgramLabel.Name = "TimerProgramLabel";
            this.TimerProgramLabel.Size = new System.Drawing.Size(78, 13);
            this.TimerProgramLabel.TabIndex = 60;
            this.TimerProgramLabel.Text = "Program Timer:";
            // 
            // ProgramTimerLabel
            // 
            this.ProgramTimerLabel.AutoSize = true;
            this.ProgramTimerLabel.Location = new System.Drawing.Point(463, 29);
            this.ProgramTimerLabel.Name = "ProgramTimerLabel";
            this.ProgramTimerLabel.Size = new System.Drawing.Size(13, 13);
            this.ProgramTimerLabel.TabIndex = 61;
            this.ProgramTimerLabel.Text = "0";
            // 
            // PauzeProgramLabel
            // 
            this.PauzeProgramLabel.AutoSize = true;
            this.PauzeProgramLabel.Location = new System.Drawing.Point(264, 53);
            this.PauzeProgramLabel.Name = "PauzeProgramLabel";
            this.PauzeProgramLabel.Size = new System.Drawing.Size(104, 13);
            this.PauzeProgramLabel.TabIndex = 65;
            this.PauzeProgramLabel.Text = "Pauze/Play Program";
            // 
            // OpenProgramButton2
            // 
            this.OpenProgramButton2.Location = new System.Drawing.Point(165, 20);
            this.OpenProgramButton2.Name = "OpenProgramButton2";
            this.OpenProgramButton2.Size = new System.Drawing.Size(96, 23);
            this.OpenProgramButton2.TabIndex = 67;
            this.OpenProgramButton2.Text = "Open Program";
            this.OpenProgramButton2.UseVisualStyleBackColor = true;
            this.OpenProgramButton2.Click += new System.EventHandler(this.OpenProgramButton2_Click);
            // 
            // StartProgramButton
            // 
            this.StartProgramButton.Location = new System.Drawing.Point(267, 20);
            this.StartProgramButton.Name = "StartProgramButton";
            this.StartProgramButton.Size = new System.Drawing.Size(84, 23);
            this.StartProgramButton.TabIndex = 68;
            this.StartProgramButton.Text = "Start Program";
            this.StartProgramButton.UseVisualStyleBackColor = true;
            this.StartProgramButton.Click += new System.EventHandler(this.StartProgramButton_Click);
            // 
            // CloseProgramButton2
            // 
            this.CloseProgramButton2.Location = new System.Drawing.Point(357, 19);
            this.CloseProgramButton2.Name = "CloseProgramButton2";
            this.CloseProgramButton2.Size = new System.Drawing.Size(89, 23);
            this.CloseProgramButton2.TabIndex = 69;
            this.CloseProgramButton2.Text = "Close Program";
            this.CloseProgramButton2.UseVisualStyleBackColor = true;
            // 
            // PauzePlayButton
            // 
            this.PauzePlayButton.Location = new System.Drawing.Point(267, 69);
            this.PauzePlayButton.Name = "PauzePlayButton";
            this.PauzePlayButton.Size = new System.Drawing.Size(101, 23);
            this.PauzePlayButton.TabIndex = 70;
            this.PauzePlayButton.Text = "Click to pauze";
            this.PauzePlayButton.UseVisualStyleBackColor = true;
            this.PauzePlayButton.Click += new System.EventHandler(this.PauzePlayButton_Click);
            // 
            // StopProgramButton
            // 
            this.StopProgramButton.Location = new System.Drawing.Point(267, 98);
            this.StopProgramButton.Name = "StopProgramButton";
            this.StopProgramButton.Size = new System.Drawing.Size(84, 23);
            this.StopProgramButton.TabIndex = 71;
            this.StopProgramButton.Text = "Stop Program";
            this.StopProgramButton.UseVisualStyleBackColor = true;
            this.StopProgramButton.Click += new System.EventHandler(this.StopProgramButton_Click);
            // 
            // SerialOutputLabel
            // 
            this.SerialOutputLabel.AutoSize = true;
            this.SerialOutputLabel.Location = new System.Drawing.Point(407, 108);
            this.SerialOutputLabel.Name = "SerialOutputLabel";
            this.SerialOutputLabel.Size = new System.Drawing.Size(165, 13);
            this.SerialOutputLabel.TabIndex = 72;
            this.SerialOutputLabel.Text = "Serial output Rcode:(stapposities)";
            // 
            // SerialOutputValueLabel
            // 
            this.SerialOutputValueLabel.AutoSize = true;
            this.SerialOutputValueLabel.Location = new System.Drawing.Point(407, 130);
            this.SerialOutputValueLabel.Name = "SerialOutputValueLabel";
            this.SerialOutputValueLabel.Size = new System.Drawing.Size(28, 13);
            this.SerialOutputValueLabel.TabIndex = 73;
            this.SerialOutputValueLabel.Text = "-------";
            // 
            // CodeInputLabel
            // 
            this.CodeInputLabel.AutoSize = true;
            this.CodeInputLabel.Location = new System.Drawing.Point(407, 53);
            this.CodeInputLabel.Name = "CodeInputLabel";
            this.CodeInputLabel.Size = new System.Drawing.Size(62, 13);
            this.CodeInputLabel.TabIndex = 74;
            this.CodeInputLabel.Text = "Code Input:";
            // 
            // CodeInputValueLabel
            // 
            this.CodeInputValueLabel.AutoSize = true;
            this.CodeInputValueLabel.Location = new System.Drawing.Point(407, 74);
            this.CodeInputValueLabel.Name = "CodeInputValueLabel";
            this.CodeInputValueLabel.Size = new System.Drawing.Size(28, 13);
            this.CodeInputValueLabel.TabIndex = 75;
            this.CodeInputValueLabel.Text = "-------";
            // 
            // SerialtestLabel
            // 
            this.SerialtestLabel.AutoSize = true;
            this.SerialtestLabel.Location = new System.Drawing.Point(622, 119);
            this.SerialtestLabel.Name = "SerialtestLabel";
            this.SerialtestLabel.Size = new System.Drawing.Size(50, 13);
            this.SerialtestLabel.TabIndex = 76;
            this.SerialtestLabel.Text = "Serialtest";
            // 
            // ComNameLabel
            // 
            this.ComNameLabel.AutoSize = true;
            this.ComNameLabel.Location = new System.Drawing.Point(9, 5);
            this.ComNameLabel.Name = "ComNameLabel";
            this.ComNameLabel.Size = new System.Drawing.Size(65, 13);
            this.ComNameLabel.TabIndex = 78;
            this.ComNameLabel.Text = "ChangeCom";
            // 
            // COMselectSwitchButton
            // 
            this.COMselectSwitchButton.Location = new System.Drawing.Point(74, 2);
            this.COMselectSwitchButton.Name = "COMselectSwitchButton";
            this.COMselectSwitchButton.Size = new System.Drawing.Size(64, 19);
            this.COMselectSwitchButton.TabIndex = 79;
            this.COMselectSwitchButton.Text = "COM6";
            this.COMselectSwitchButton.UseVisualStyleBackColor = true;
            this.COMselectSwitchButton.Click += new System.EventHandler(this.COMselectSwitchButton_Click);
            // 
            // SerialInputTextBox
            // 
            this.SerialInputTextBox.Enabled = false;
            this.SerialInputTextBox.Location = new System.Drawing.Point(89, 74);
            this.SerialInputTextBox.Multiline = true;
            this.SerialInputTextBox.Name = "SerialInputTextBox";
            this.SerialInputTextBox.ReadOnly = true;
            this.SerialInputTextBox.Size = new System.Drawing.Size(129, 69);
            this.SerialInputTextBox.TabIndex = 44;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(704, 524);
            this.Controls.Add(this.SerialInputTextBox);
            this.Controls.Add(this.COMselectSwitchButton);
            this.Controls.Add(this.ComNameLabel);
            this.Controls.Add(this.SerialtestLabel);
            this.Controls.Add(this.CodeInputValueLabel);
            this.Controls.Add(this.CodeInputLabel);
            this.Controls.Add(this.SerialOutputValueLabel);
            this.Controls.Add(this.SerialOutputLabel);
            this.Controls.Add(this.StopProgramButton);
            this.Controls.Add(this.PauzePlayButton);
            this.Controls.Add(this.CloseProgramButton2);
            this.Controls.Add(this.StartProgramButton);
            this.Controls.Add(this.OpenProgramButton2);
            this.Controls.Add(this.PauzeProgramLabel);
            this.Controls.Add(this.ProgramTimerLabel);
            this.Controls.Add(this.TimerProgramLabel);
            this.Controls.Add(this.StatusWaardeLabel);
            this.Controls.Add(this.StatusLabel);
            this.Controls.Add(this.TabControl);
            this.Controls.Add(this.DisconnectSerialsButton);
            this.Controls.Add(this.StatusComLabel3);
            this.Controls.Add(this.StatusComLabel2);
            this.Controls.Add(this.StatusComLabel1);
            this.Controls.Add(this.OpenPortsButton);
            this.Name = "Form1";
            this.Text = "MEGA GLASS BENDERMAN 3000";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.TabControl.ResumeLayout(false);
            this.RemoteTabPage.ResumeLayout(false);
            this.RemoteTabPage.PerformLayout();
            this.Programma.ResumeLayout(false);
            this.Programma.PerformLayout();
            this.InversePosCalcuTabPage.ResumeLayout(false);
            this.InversePosCalcuTabPage.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button OpenPortsButton;
        private System.Windows.Forms.Label StatusComLabel1;
        private System.Windows.Forms.Label StatusComLabel2;
        private System.Windows.Forms.Label StatusComLabel3;
        private System.Windows.Forms.Label RemoteArmControlLabel;
        private System.Windows.Forms.Label J1AngleLabel;
        private System.Windows.Forms.Label J2AngleLabel;
        private System.Windows.Forms.TextBox J1AngleTextbox;
        private System.Windows.Forms.TextBox J2AngleTextbox;
        private System.Windows.Forms.Label Z1PositionLabel;
        private System.Windows.Forms.TextBox Z1PositionTextBox;
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.Button J1StuurButton;
        private System.Windows.Forms.Button J2StuurButton;
        private System.Windows.Forms.Button Z1StuurButton;
        private System.Windows.Forms.Button DisconnectSerialsButton;
        private System.Windows.Forms.Label WriteProgramLabel;
        private System.Windows.Forms.ComboBox StappenComboBox;
        private System.Windows.Forms.Label StapLabel;
        private System.Windows.Forms.Label StapPosXLabel;
        private System.Windows.Forms.TextBox StapPosZTextbox;
        private System.Windows.Forms.TextBox StapStarttijdTextbox;
        private System.Windows.Forms.Label StarttijdStapLabel;
        private System.Windows.Forms.Button SaveStapButton;
        private System.Windows.Forms.Label AantalStappenLabel;
        private System.Windows.Forms.Label OutputHuidigAantalStappenLabel;
        private System.Windows.Forms.Button NieuwProgrammaButton;
        private System.Windows.Forms.TextBox ProgramShowTextBox;
        private System.Windows.Forms.Button OpenProgramButton;
        private System.Windows.Forms.Button CloseProgramButton;
        private System.Windows.Forms.Button EditProgramButton;
        private System.Windows.Forms.TextBox NewFileNameTextBox;
        private System.Windows.Forms.Label FileNameLabel;
        private System.Windows.Forms.Button SaveNewProgramButton;
        private System.Windows.Forms.Button ReWriteProgramButton;
        private System.Windows.Forms.Label TestSaveStapWaardeLabel;
        private System.Windows.Forms.TextBox FileName2TextBox;
        private System.Windows.Forms.Label FileName2Label;
        private System.Windows.Forms.Button NewProgramButton;
        private System.Windows.Forms.Label InverseKinematicLabel;
        private System.Windows.Forms.Label DesiredPositionLabel;
        private System.Windows.Forms.TextBox InverXTextBox;
        private System.Windows.Forms.TextBox InverYTextBox;
        private System.Windows.Forms.TextBox InverZTextBox;
        private System.Windows.Forms.Button NewCalcuButton;
        private System.Windows.Forms.Button CalculateButton;
        private System.Windows.Forms.Label InverXLabel;
        private System.Windows.Forms.Label InverYLabel;
        private System.Windows.Forms.Label InverZLabel;
        private System.Windows.Forms.Button SendPositionButton;
        private System.Windows.Forms.Label J1Label;
        private System.Windows.Forms.Label J2Label;
        private System.Windows.Forms.Label ZLabel;
        private System.Windows.Forms.Label J1WaardeLabel;
        private System.Windows.Forms.Label J2WaardeLabel;
        private System.Windows.Forms.Label ZWaardeLabel;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.TabControl TabControl;
        private System.Windows.Forms.TabPage RemoteTabPage;
        private System.Windows.Forms.TabPage Programma;
        private System.Windows.Forms.TabPage InversePosCalcuTabPage;
        private System.Windows.Forms.Label StatusLabel;
        private System.Windows.Forms.Label StatusWaardeLabel;
        private System.Windows.Forms.Label TimerProgramLabel;
        private System.Windows.Forms.Label ProgramTimerLabel;
        private System.Windows.Forms.Label PauzeProgramLabel;
        private System.Windows.Forms.Button OpenProgramButton2;
        private System.Windows.Forms.Button StartProgramButton;
        private System.Windows.Forms.Button CloseProgramButton2;
        private System.Windows.Forms.Button PauzePlayButton;
        private System.Windows.Forms.Button StopProgramButton;
        private System.Windows.Forms.Label SerialOutputLabel;
        private System.Windows.Forms.Label SerialOutputValueLabel;
        private System.Windows.Forms.TextBox StapPosYTextbox;
        private System.Windows.Forms.TextBox StapPosXTextbox;
        private System.Windows.Forms.Label StapPosZLabel;
        private System.Windows.Forms.Label StapPosYLabel;
        private System.Windows.Forms.Label TestSaveStapLabel;
        private System.Windows.Forms.Label CodeInputLabel;
        private System.Windows.Forms.Label CodeInputValueLabel;
        private System.Windows.Forms.Label SerialtestLabel;
        private System.Windows.Forms.Label ComNameLabel;
        private System.Windows.Forms.Button COMselectSwitchButton;
        private System.Windows.Forms.TextBox SerialInputTextBox;
    }
}

