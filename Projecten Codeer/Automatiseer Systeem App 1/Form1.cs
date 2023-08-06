using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.IO;
using static System.Net.Mime.MediaTypeNames;
using System.Timers;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using System.Configuration;
using System.Net.NetworkInformation;
using System.Threading;
using System.Runtime.InteropServices;

namespace Automatiseer_Systeem_App_1
{



    public partial class Form1 : Form
    {
        //-------------------------Variabelen Cyclus Programma-------------------------------------------------------

        System.Timers.Timer ProgrammaUitvoerTimer;
        System.Timers.Timer ReadSerialDataTimer;
        System.Timers.Timer millisecTimer;
        int  s;
        int sensora = 0;
        int sensorb = 0;
        char serialchar;
        static bool progamOn = false;
        static bool moveready = false;
        string programmatext = "";
        Stappen stap1 = new Stappen();
        Stappen stap2 = new Stappen();
        Stappen stap3 = new Stappen();
        Stappen stap4 = new Stappen();
        Stappen stap5 = new Stappen();
        Stappen stap6 = new Stappen();
        Stappen stap7 = new Stappen();
        Stappen stap8 = new Stappen();
        Stappen stap9 = new Stappen();
        UploadStappen step1 = new UploadStappen();
        UploadStappen step2 = new UploadStappen();
        UploadStappen step3 = new UploadStappen();
        UploadStappen step4 = new UploadStappen();
        UploadStappen step5 = new UploadStappen();
        UploadStappen step6 = new UploadStappen();
        UploadStappen step7 = new UploadStappen();
        UploadStappen step8 = new UploadStappen();
        UploadStappen step9 = new UploadStappen();

        string statustext = "---";
        string serialtext = "---";
        static int mm = 0;


       // public static void WorkThreadFunction()
        //{
        //}
        //Thread thread = new Thread(new ThreadStart(Form1.WorkThreadFunction));
       // thread.Start(); 

        //------------------------------Cyclus Programma--------------------------------------------------------------------------------


        public Form1()
        {
            InitializeComponent();
        }
       

        private void Form1_Load(object sender, EventArgs e)
        {
            ProgrammaUitvoerTimer = new System.Timers.Timer();
            ProgrammaUitvoerTimer.Interval = 1000;
            ProgrammaUitvoerTimer.Elapsed += OnTimeEventProgramma;
            ReadSerialDataTimer = new System.Timers.Timer();
            ReadSerialDataTimer.Interval = 500;
            ReadSerialDataTimer.Elapsed += OnTimeEventSerial; 
            millisecTimer = new System.Timers.Timer();
            millisecTimer.Interval = 1;
            
            //millisecTimer.Elapsed += ;
        }//beschrijft timer
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            //ReadSerialDataTimer.Stop();

        }


        private static void DataReceivedHandler(
                       object sender,
                       SerialDataReceivedEventArgs e)
        {
            SerialPort sp = (SerialPort)sender;
            string indata = sp.ReadExisting();
            Console.WriteLine("Data Received:");
            Console.Write(indata);
        }
        public void OnTimeEventProgramma(object sender, ElapsedEventArgs e)
        {
            
           Invoke(new Action(() =>
            {        
                s += 1;

                int sec = s;

                ProgramTimerLabel.Text = s.ToString();
                SerialtestLabel.Text = Convert.ToString(mm);
                // SerialOutputValueLabel.Text = serialtext;
                // StatusWaardeLabel.Text = statustext;
            }));
         
            
            //  moveready = true;



            if (progamOn && moveready) 
            { 
            RunProgram();
            }
            
        }//Voert uit per 1000ms wanneer timer.Start()
        public void OnTimeEventSerial(object sender, ElapsedEventArgs e)
        {

            Invoke(new Action(() =>
            {
                //SerialInputTextBox.Text = currentReceived;
                //checkSensors();
                // StatusWaardeLabel.Text = statustext;
            }));

            //  moveready = true;

        }//Voert uit per 500ms wanneer timer.Start()

     
        private void checkSensors()
        {
            if(currentReceived == "Z")
            {
                ProgrammaUitvoerTimer.Stop();
                
            }
            if(currentReceived == "A" && ProgrammaUitvoerTimer.Enabled == false)
            {
                ProgrammaUitvoerTimer.Start();
            }
            
        }
        
        private void OpenProgramButton2_Click(object sender, EventArgs e)
        {
            Stream st;

            OpenFileDialog d1 = new OpenFileDialog();

            // using (OpenFileDialog openFileDialog = new OpenFileDialog())
            d1.InitialDirectory = @"C:\Users\rikve\Desktop\PROJECT\Mech projecten laptopmap\Robot Arm Bouw Hoofdmap\Programmas\Gcode path\";
            String str ="";
            //{
            if (d1.ShowDialog() == DialogResult.OK)
            {

                if ((st = d1.OpenFile()) != null)
                {
                    string file = d1.FileName;

                    str = File.ReadAllText(file);
                    ProgramShowTextBox.Text = str;

                }
                //"1 5 152 122 231\r\1 10 152 122 231"

                string path = d1.InitialDirectory;


                string result = Path.GetFileNameWithoutExtension(d1.FileName);


                st.Close();
                programmatext = str;
                int hvllijnen = 0;
                string[] separator = {"\r\n", "For"};
                string[] lijnen = str.Split(separator, StringSplitOptions.RemoveEmptyEntries);
                int i = 0;
                try
                {
                 //  while(!string.IsNullOrWhiteSpace(lijnen[i]))
                    //{ 
                    if()
                        stap1.lijn = lijnen[i];
                        stap1.ha();
                        hvllijnen++;
                    //}
                    if (!string.IsNullOrWhiteSpace(lijnen[1]))
                    {                    
                        stap2.lijn = lijnen[1];
                        stap2.ha();
                        hvllijnen++;
                    }
                    if (!string.IsNullOrWhiteSpace(lijnen[2]))
                    {
                        stap3.lijn = lijnen[2];
                        stap3.ha();
                        hvllijnen++;
                    }
                    if (!string.IsNullOrWhiteSpace(lijnen[3]))
                    {
                        stap4.lijn = lijnen[3];
                        stap4.ha();
                        hvllijnen++;
                    }
                    if (!string.IsNullOrWhiteSpace(lijnen[4]))
                    {
                        stap5.lijn = lijnen[4];
                        stap5.ha();
                        hvllijnen++;
                    }
                    if (!string.IsNullOrWhiteSpace(lijnen[5]))
                    {
                        stap6.lijn = lijnen[5];
                        stap6.ha();
                        hvllijnen++;
                    }
                    if (!string.IsNullOrWhiteSpace(lijnen[6]))
                    {
                        stap7.lijn = lijnen[6];
                        stap7.ha();
                        hvllijnen++;
                    }
                    if (!string.IsNullOrWhiteSpace(lijnen[7]))
                    {
                        stap8.lijn = lijnen[7];
                        stap8.ha();
                        hvllijnen++;
                    }
                    if (!string.IsNullOrWhiteSpace(lijnen[8]))
                    {
                        stap9.lijn = lijnen[8];
                        stap9.ha();
                        hvllijnen++;
                    }
                }
                catch (Exception ex)
                {
                    StatusWaardeLabel.Text = "hmmm " + hvllijnen + " lijnen";                    
                }
                            
            }

            
        }

      
            private void StartProgramButton_Click(object sender, EventArgs e)
        {
            progamOn = true;
            moveready = true;
            ProgrammaUitvoerTimer.Start();

           // serialPort1.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);

        }//ProgramOn = true en timer start

        private void StopProgramButton_Click(object sender, EventArgs e)
        {
            progamOn = false;
            ProgrammaUitvoerTimer.Stop();
            s = 0;
            ProgramTimerLabel.Text = "0";
            SerialOutputValueLabel.Text = "---";
            StatusWaardeLabel.Text = "----";

        }

        private void PauzePlayButton_Click(object sender, EventArgs e)
        {
            ProgrammaUitvoerTimer.Stop();
        }


        public void RunProgram()
        {
            bool a = false;//deze switch moet nog weg waarshijnlijk
            Invoke(new Action(() =>
            {
                switch (a)
                {
                    case true:
                        statustext = "Status: voorwaardes ontbreken";
                        break;
  
                    default:
                        if (s == stap1.Starttijd)
                        {
                            StatusWaardeLabel.Text = "Status: geen voorwaardes ontbreken";
                            CodeInputLabel.Text = $"J1:{stap1.J1pos} J2: {stap1.J2pos} Z: {stap1.Zpos}";
                            //SerialOutputValueLabel.Text = stap1.Rcode;
                            //serialPort1.WriteLine(stap1.Rcode);
                        }
                        if (s == stap2.Starttijd)
                        {
                            StatusWaardeLabel.Text = "Status: geen voorwaardes ontbreken";
                            CodeInputLabel.Text = $"J1:{stap2.J1pos} J2: {stap2.J2pos} Z: {stap2.Zpos}";
                        /*    SerialOutputValueLabel.Text = stap2.Rcode;
                            serialPort1.WriteLine(stap2.Rcode);*/
                        }
                        if (s == stap3.Starttijd)
                        {
                            StatusWaardeLabel.Text = "Status: geen voorwaardes ontbreken";
                            CodeInputLabel.Text = $"J1:{stap3.J1pos} J2: {stap3.J2pos} Z: {stap3.Zpos}";
                        /*    SerialOutputValueLabel.Text = stap3.Rcode;
                            serialPort1.WriteLine(stap3.Rcode);*/
                        }
                        break;
                }
            }
               ));
           }//Functie bij StartProgramButton, wanneer starttijd stap waar is: status en stap weergeven, waardes van commandos per stap versturen via serial in juiste format


        //--------------------------------COM PORTS-----------------------------------------------------------
        string currentReceived = string.Empty;
        string receivedStr = string.Empty;

        private void OpenPortsButton_Click(object sender, EventArgs e)
        {
            try
            {
            serialPort1.PortName = COMselectSwitchButton.Text;
            serialPort1.BaudRate = 9600;
            serialPort1.Open();
            ReadSerialDataTimer.Start();
            serialPort1.DataReceived += new SerialDataReceivedEventHandler(serialPort1_DataReceived);

            J1AngleTextbox.Enabled = true;
            J2AngleTextbox.Enabled = true;
            Z1PositionTextBox.Enabled = true;
            J1StuurButton.Enabled = true;
            J2StuurButton.Enabled = true;
            Z1StuurButton.Enabled = true;
            StatusWaardeLabel.Text = COMselectSwitchButton.Text +" gekozen";
            OpenPortsButton.Enabled = false;
            }
            catch (System.IO.IOException)
            {
                StatusWaardeLabel.Text = COMselectSwitchButton.Text + " poort niet open";
            }
        }
        void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {         
            currentReceived = serialPort1.ReadTo("\r\n");
            receivedStr += currentReceived;
            char[] strarray = currentReceived.ToCharArray();
            Invoke(new Action(() =>
            {
                SerialInputTextBox.Text = currentReceived;
               // checkSensors();
                // StatusWaardeLabel.Text = statustext;
            }));
/*
            if (strarray[0] == 'Z')
            {
                ProgrammaUitvoerTimer.Stop();

            }
            if (strarray[0] == 'A' && ProgrammaUitvoerTimer.Enabled == false)
            {
                ProgrammaUitvoerTimer.Start();
            }
            //SerialInputTextBox.Text = currentReceived;
*/
        }

        private void DisconnectSerialsButton_Click(object sender, EventArgs e)
        {
            serialPort1.Close();
            ReadSerialDataTimer.Close();
            J1AngleTextbox.Enabled = true;
            J2AngleTextbox.Enabled = true;
            Z1PositionTextBox.Enabled = true;
            J1StuurButton.Enabled = true;
            J2StuurButton.Enabled = true;
            Z1StuurButton.Enabled = true;
            OpenPortsButton.Enabled = true;
        }
        private void COMselectSwitchButton_Click(object sender, EventArgs e)
        {

            if (COMselectSwitchButton.Text == "COM8")
            {
                COMselectSwitchButton.Text = "COM6";
            }
            else if (COMselectSwitchButton.Text == "COM6")
            {
                COMselectSwitchButton.Text = "COM3";
            }
            else if (COMselectSwitchButton.Text == "COM3")
            {
                COMselectSwitchButton.Text = "COM8";
            }

        }

        //-----------------Remote--------------------------------------------------------------------------
        private void J1StuurButton_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("Ja" + J1AngleTextbox.Text);
            J1AngleTextbox.Text = "";
        }
        private void J2StuurButton_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("Jb" + J2AngleTextbox.Text);
            J2AngleTextbox.Text = "";
        }
        private void Z1StuurButton_Click(object sender, EventArgs e)
        {
            serialPort1.WriteLine("Z1" + Z1PositionTextBox.Text);
            Z1PositionTextBox.Text = "";
        }
        //-----------------Manual programma invoer---------------------------------------------------------
        //-----------------Variabelen-------

        string a1 = "";
        string a2 = "";
        string a3 = "";
        string a4 = "";
        string a5 = "";
        string a6 = "";
        string a7 = "";
        string a8 = "";
        string a9 = "";
        string totaal = "leeg";
        int aa = 0;

        string deX = "";
        string deY = "";
        string deZ = "";
        string deStarttijd = "";
        string Hoek1 = "";
        string Hoek2 = "";
        string Zpos = "";
        float J1a = 0;
        float J2a = 0;
        double J1aa = 0;
        double J2aa = 0;

        //---------------------------------
        private void StappenComboBox_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void NieuwProgrammaButton_Click(object sender, EventArgs e)
        {
            SaveNewProgramButton.Enabled = false;
            StapStarttijdTextbox.Enabled = true;
            StappenComboBox.Enabled = true;
            StapPosXTextbox.Enabled = true;
            StapPosYTextbox.Enabled = true;
            StapPosZTextbox.Enabled = true;
            SaveStapButton.Enabled = true;
            NewFileNameTextBox.Enabled = true;



        }

        private void SaveNewProgramButton_Click(object sender, EventArgs e)
        {

            
            string fileName = NewFileNameTextBox.Text;
            string path = @"C:\Users\rikve\Desktop\PROJECT\Mech projecten laptopmap\Robot Arm Bouw Hoofdmap\Programmas\Gcode path\" + fileName + ".txt";
            if (!File.Exists(path))
            {
                using (StreamWriter sw = new StreamWriter(path))
                {
                    sw.WriteLine(totaal);
                }
            }
            SaveNewProgramButton.Enabled = false;
            StapStarttijdTextbox.Enabled = false;
            StappenComboBox.Enabled = false;
            StapPosZTextbox.Enabled = false;
            SaveStapButton.Enabled = false;
            NewFileNameTextBox.Enabled = false;

        }
        public void InverseCalculate()
        {
            float Xa = 1;
            float Ya = 1;
            float Za = 1;
            try
            {

                Za = float.Parse(deZ);
                Ya = float.Parse(deY); //Desired Yposition of end-effector in mm
                Xa = float.Parse(deX); //Desired Y position of end-effector in mm

            }
            catch (FormatException)
            {
                StatusWaardeLabel.Text = "Format X,Y of Z inverse niet juist";
            }


            float r1 = 0;
            float phi1 = 0;
            float phi2 = 0;
            float phi3 = 0;
            float a1 = 100;
            float a2 = 200;
            float a3 = 100;
            float a4 = 200;
            float T1 = 0; // theta 1 in !radians
            float T2 = 0;
            
            //functie Theta1 neemt hoek in graden
            float bereik1 = (float)Math.Pow(Xa, 2) + (float)Math.Pow(Ya, 2);

            //((X > 100 || X < -100) && (Y > 100 || Y < -100)
            // && (X < 400 || X > -400) && (Y < 400 || Y > -400))
            if (bereik1 < (float)Math.Pow(400, 2) && (bereik1 > (float)Math.Pow(100, 2)) && (Za > 0 && Za < 100))
            {
                r1 = (float)Math.Sqrt(Xa * Xa + Ya * Ya); //eq.1c

                phi1 = (float)Math.Acos(((a4 * a4) - (a2 * a2) - (r1 * r1)) / (-2 * a2 * r1)); //eq.2
                phi2 = (float)Math.Atan(Ya / Xa); //eq.3
                T1 = phi2 - phi1; //eq.4
                phi3 = (float)Math.Acos(((r1 * r1) - (a2 * a2) - (a4 * a4)) / (-2 * a2 * a4)); //eq.5
                T2 = (float)3.141459 - phi3; //eq.6(180gr in radiants)
                J1a = Reken.RadtoDegr(T1);
                J2a = Reken.RadtoDegr(T2);
                J1aa = Math.Round(J1a, 3);//float J1a naar double Round J1aa
                J2aa = Math.Round(J2a, 3);
                Hoek1 = J1aa.ToString();// voor tekst stap save
                Hoek2 = J2aa.ToString();
                Zpos = Za.ToString();
                

            }
            if (Za > 100 || Za < 0)
            {
                Zpos = "OutRange";
            }
            if (bereik1 > (float)Math.Pow(400, 2) || (bereik1 < (float)Math.Pow(100, 2)))
            {
                Hoek1 = "OutRange";
                Hoek2 = "OutRange";
            }
  
        }
        private void SaveStapButton_Click(object sender, EventArgs e)
        {
            
            SaveNewProgramButton.Enabled = true;
            MyClass newstep = new MyClass();
            string destap = StappenComboBox.Text;
            deX = StapPosXTextbox.Text;
            deY = StapPosYTextbox.Text;
            deZ = StapPosZTextbox.Text;
            //InverseCalculate();
            deStarttijd = StapStarttijdTextbox.Text;
            string text = newstep.stap(destap, deX, deY, deZ, deStarttijd);
            char[] chars = text.ToCharArray();
            // string charnull = chars[0];
            // int char0 = Int32.Parse(chars[0]);

            
            
            switch (chars[0])
            {
                case '1':
                    a1 = text;
                    step1.Starttijd = deStarttijd;
                    step1.Xpos = deX;
                    step1.Ypos = deY;
                    step1.Zpos = deZ;
                    //step1.lijn = text;
                    break;
                case '2':
                    a2 = text;
                    step2.Starttijd = deStarttijd;
                    step2.Xpos = deX;
                    step2.Ypos = deY;
                    step2.Zpos = deZ;
                    //step2.lijn = text;
                    break;
                case '3':
                    a3 = text;
                    step3.Starttijd = deStarttijd;
                    step3.Xpos = deX;
                    step3.Ypos = deY;
                    step3.Zpos = deZ;
                   // step3.lijn = text;
                    break;
               


            }
            
           
            totaal = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9;
            TestSaveStapWaardeLabel.Text = totaal;
        }

        private void OpenProgramButton_Click(object sender, EventArgs e)
        {
            FileName2TextBox.Enabled = false;
            ProgramShowTextBox.Enabled = false;

            Stream st;

            OpenFileDialog d1 = new OpenFileDialog();

            // using (OpenFileDialog openFileDialog = new OpenFileDialog())
            d1.InitialDirectory = @"C:\Users\rikve\Desktop\PROJECT\Mech projecten laptopmap\Robot Arm Bouw Hoofdmap\Programmas\Gcode path\";

            //{
            if (d1.ShowDialog() == DialogResult.OK)
            {

                if ((st = d1.OpenFile()) != null)
                {
                    string file = d1.FileName;

                    String str = File.ReadAllText(file);
                    ProgramShowTextBox.Text = str;

                }


                string path = d1.InitialDirectory;
                string result;

                result = Path.GetFileNameWithoutExtension(d1.FileName);

                FileName2TextBox.Text = result;
                st.Close();
            }
        }

        private void CloseProgramButton_Click(object sender, EventArgs e)
        {
            ProgramShowTextBox.Enabled = false;
            ProgramShowTextBox.ReadOnly = true;
            FileName2TextBox.Enabled = false;
        }

        private void EditProgramButton_Click(object sender, EventArgs e)
        {
            ProgramShowTextBox.Enabled = true;
            ProgramShowTextBox.ReadOnly = false;
            FileName2TextBox.Enabled = true;
            FileName2TextBox.ReadOnly = false;
        }

        private void ReWriteProgramButton_Click(object sender, EventArgs e)
        {

            StreamWriter A = new StreamWriter(@"C:\Users\rikve\Desktop\PROJECT\Mech projecten laptopmap\Robot Arm Bouw Hoofdmap\Programmas\Gcode path\" + FileName2TextBox.Text + ".txt");
            //using (StreamWriter A = fi1.CreateText()) ;

            String Code = Convert.ToString(ProgramShowTextBox.Text);
            A.WriteLine(Code);
            A.Close();
        }

        private void NewProgramButton_Click(object sender, EventArgs e)
        {
            FileName2TextBox.ReadOnly = false;
            ProgramShowTextBox.Enabled = true;
            ProgramShowTextBox.ReadOnly = false;
            FileName2TextBox.Enabled = true;
        }

        //-----------------Inverse Position Calcu---------------------------------------------------------


        private void NewCalcuButton_Click(object sender, EventArgs e)
        {
            InverXTextBox.Enabled = true;
            InverYTextBox.Enabled = true;
            InverZTextBox.Enabled = true;
            InverXTextBox.Text = "";
            InverYTextBox.Text = "";
            InverZTextBox.Text = "";
            J1WaardeLabel.Text = "";
            J2WaardeLabel.Text = "";
            ZWaardeLabel.Text = "";
        }

        private void CalculateButton_Click(object sender, EventArgs e)
        {
            float X = 1;
            float Y = 1;
            float Z = 1;
            try
            {

                Z = float.Parse(InverZTextBox.Text);
                Y = float.Parse(InverYTextBox.Text); //Desired Yposition of end-effector in mm
                X = float.Parse(InverXTextBox.Text); //Desired Y position of end-effector in mm

            }
            catch (FormatException)
            {
                StatusWaardeLabel.Text = "Format X,Y of Z inverse niet juist";
            }


            float r1 = 0;
            float phi1 = 0;
            float phi2 = 0;
            float phi3 = 0;
            float a1 = 100;
            float a2 = 200;
            float a3 = 100;
            float a4 = 200;
            float T1 = 0; // theta 1 in !radians
            float T2 = 0;
            //functie Theta1 neemt hoek in graden
            float bereik1 = (float)Math.Pow(X, 2) + (float)Math.Pow(Y, 2);

            //((X > 100 || X < -100) && (Y > 100 || Y < -100)
            // && (X < 400 || X > -400) && (Y < 400 || Y > -400))
            if (bereik1 < (float)Math.Pow(400, 2) && (bereik1 > (float)Math.Pow(100, 2)) && (Z > 0 && Z < 100))
            {
                r1 = (float)Math.Sqrt(X * X + Y * Y); //eq.1c

                phi1 = (float)Math.Acos(((a4 * a4) - (a2 * a2) - (r1 * r1)) / (-2 * a2 * r1)); //eq.2
                phi2 = (float)Math.Atan(Y / X); //eq.3
                T1 = phi2 - phi1; //eq.4
                phi3 = (float)Math.Acos(((r1 * r1) - (a2 * a2) - (a4 * a4)) / (-2 * a2 * a4)); //eq.5
                T2 = (float)3.141459 - phi3; //eq.6(180gr in radiants)
                float J1 = Reken.RadtoDegr(T1);
                float J2 = Reken.RadtoDegr(T2);

                string Joint1 = J1.ToString();
                string Joint2 = J2.ToString();
                string Zas = Z.ToString();

                J1WaardeLabel.Text = Joint1;
                J2WaardeLabel.Text = Joint2;
                ZWaardeLabel.Text = Zas;
            }
            if(Z > 100 || Z < 0)
            {
                ZWaardeLabel.Text = "OutRange";
            }
            if (bereik1 > (float)Math.Pow(400, 2) || (bereik1 < (float)Math.Pow(100, 2)))
            {
                J1WaardeLabel.Text = "OutRange";
                J2WaardeLabel.Text = "OutRange";
            }

            // else if( (bereik1 < (float)Math.Pow(400, 2)) && (bereik1 > (float)Math.Pow(100, 2)) )
            // {
            //     J1WaardeLabel.Text = "OutRange";
            //     J2WaardeLabel.Text = "OutRange";
            // }
            // else if (Z < 0 || Z > 100)
            // {
            //     ZWaardeLabel.Text = "OutRange";
            // }


        }
        private void SendPositionButton_Click(object sender, EventArgs e)
        {
           string a = "J1"+J1WaardeLabel.Text;
           string b = "J2"+J2WaardeLabel.Text;
           string c = "Z"+ZWaardeLabel.Text;


            try
            {
                serialPort1.WriteLine(a);
                serialPort1.WriteLine(b);
                serialPort1.WriteLine(c);
            }
            catch (System.InvalidOperationException)
            {
                StatusWaardeLabel.Text = "COM3 poort niet open";
            }
        }

    


        //--------------------------------Einde Inverse Pos Calcu---------------------------------------



    }
    public class MyClass
    {
        public int stapnaam;
        public string stapnaam1;
        public string positieXtext;
        public string positieYtext;
        public string positieZtext;
        public string starttijdtext;


        public string stap(string stap, string Xtext, string Ytext, string positieZ, string Starttijd)
        {
            stapnaam = Int32.Parse(stap);
            positieXtext = Xtext;
            positieYtext = Ytext;
            positieZtext = positieZ;

            starttijdtext = Starttijd;
            string text = "";
            if (stapnaam > 0)
            {
                stapnaam1 = stapnaam.ToString();
                //stapnaam1 = 
                text = stapnaam + " " + starttijdtext + " " + positieXtext + " " + positieYtext + " " + positieZtext + "\r\n";
                
            }
            
            return text;
        }

    }
    public class Reken
    {
        static public float RadtoDegr(float Rad)
        {


            float Degr = (Rad / (float)3.1414599) * (float)180;
            
            return Degr;
        }




        static public string BounceValue(string a)
        {
            string b = a;
            return  b;
        }

    }
    
    public class Programma
    {
        float j1 = 1;
        float j2 = 1;
        float z = 1;
       
        //if()
        public float StatusOven(int Celsius, bool OvenLadeOpen)
        {
            // if(tijd == "00:00:05:00")
            // {
            // }
            



            return 0;
        }
        public float StatusBlower(int Celsius, bool BlowerLadeOpen)
        {
            // if(tijd == "00:00:05:00")
            // {
            // }




            return 0;
        }

        public float stap1Arm(string tijd, float J1, float J2, float AZ)
        {
            // if(tijd == "00:00:05:00")
            // {
            // }
            j1 = J1;
            string joint1 = j1.ToString();
            

            return 0;
        }
        static public float stap1Oven(string tijd, string status1, string status2)
        {
            // if(tijd == "00:00:05:00")
            // {
            // }




            return 0;
        }
        static public float stap1Blower(string tijd, string status1, string status2)
        {
            // if(tijd == "00:00:05:00")
            // {
            // }

            return 0;
        }
    }
}
