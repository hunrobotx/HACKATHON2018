#include<windows.h>
#include<tchar.h>
#include<stdio.h>
#include<math.h>

int main(int argc, _TCHAR* argv[])
{
	SYSTEM_POWER_STATUS SystemPowerStatus;
	if(GetSystemPowerStatus(&SystemPowerStatus)==0)
	{
		printf("Guc durumu hatasi al, hata kodu :%d\r\n",GetLastError());
		system("pause>nul");
		exit(0);
	}
	switch(SystemPowerStatus.ACLineStatus)
	{
	case 0:
		{
			printf("AC guc durumu: bagli degil\r\n");
			break;
		}
	case 1:
		{
			printf("AC guc durumu: bagli\r\n");
			break;
		}
	case 255:
		{
			printf("AC guc durumu: Bilinmeyen durum\r\n");
			break;
		}
	default:
		{
			printf("AC guc durumu: bilinmeyen parametreler\r\n");
			break;
		}
	}
	/*
	if(SystemPowerStatus.BatteryFlag&0x01)
	{
		printf("??????66%%");
	}
	if(SystemPowerStatus.BatteryFlag&0x02)
	{
		printf("??????33%%");
	}
	if(SystemPowerStatus.BatteryFlag&0x04)
	{
		printf("??????5%%");
	}
	*/
	if(SystemPowerStatus.BatteryFlag&0x08)
	{
		printf("Pil sarj durumu: Sarj oluyor\r\n");
	}
	if(SystemPowerStatus.BatteryFlag&0x80)
	{
		printf("Pil sarj durumu: pil yok\r\n");
	}
	/*
	if(SystemPowerStatus.BatteryFlag&0xFF)
	{
		printf("????\r\n");
	}
	*/
	if(SystemPowerStatus.BatteryLifePercent<=100)
	{
		printf("Pil yuzdesi:%d%%\r\n",SystemPowerStatus.BatteryLifePercent);
	}
	else
	{
		printf("Pil yuzdesi\r\n");
	}
	FILE*dosya;
	
	dosya = fopen("PowerOutput.txt","a");
	fprintf(dosya,"Pil yuzdesi:%d%%\r\n",SystemPowerStatus.BatteryLifePercent);
	fclose(dosya);
	return 0;
	
}

