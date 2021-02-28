<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class Descargar extends Controller
{
    public function index(Request $request)
    {

        shell_exec('apt-get update');
        shell_exec('apt-get upgrade');
        shell_exec('sudo apt-get dist-upgrade -y');
        
            echo("Iniciando Descarga Snort <br>");
       
            exec('wget https://www.snort.org/downloads/snort/daq-2.0.7.tar.gz');
           
            echo(" <br> DAQ descargando...<br>");
            echo shell_exec('sh ../bash/daq.sh');
            
            
    
            exec('wget https://www.snort.org/downloads/snort/snort-2.9.17.tar.gz');
    
            //echo(" <br> Descargando... SNORT <br>");
            echo shell_exec('sh ../bash/snort.sh');
            
    
            exec('tar xvzf daq-2.0.7.tar.gz');
            exec('tar xvzf snort-2.9.17.tar.gz');

    return view('descargar');
    }
}
