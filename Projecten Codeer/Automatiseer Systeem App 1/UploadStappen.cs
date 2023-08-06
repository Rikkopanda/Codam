using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Net.Mime.MediaTypeNames;

namespace Automatiseer_Systeem_App_1
{
    internal class UploadStappen
    {
        public string lijn = " ";
        public string Starttijd;
        public string stapnaam;
        public string Xpos;
        public string Ypos;
        public string Status;
        public string Zpos;

        

        public void ha()
        {
            lijn = stapnaam + " " + Starttijd + " " + Xpos + " " + Ypos + " " + Zpos + "\r\n";
        }
    }
}
