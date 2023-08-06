using System;

namespace steps
{
	class stap
	{
		public string stapnaam { get; set; };
		public string positietext;
		public string pauze;

		public string step(string stap, string positie, string pauz)
		{
			stapnaam = stap;
			positietext = positie;
			pauze = pauz;
		}
	}
}
