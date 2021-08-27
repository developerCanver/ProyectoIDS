<?php

namespace App\Http\Controllers;

use App\Models\InstalarReglas;
use Illuminate\Http\Request;

class InstalarReglasController extends Controller
{
    public function index(Request $request)
    {
    $reglas = InstalarReglas::get();

        return view('listaReglas',[
            'reglas' => $reglas,
        ]);
        
    }

    public function activar($id)
    {
        exec('sh bash/rules.sh', $rules);
        //dd($rules);
        
        $ar=fopen("local.rules", "a+") or die ("Error al crear el archivo");
  

  
    
        fwrite($ar,'alert icmp any any -> any any ( msg:"ICMP Traffic Detected"; sid:10000001; metadata:policy security-ips alert; )');
 
       
        //alert icmp any any -> any any ( msg:"ICMP Traffic Detected"; sid:10000001; metadata:policy security-ips alert; )
        //exec('sh bash/moverRules.sh', $rules);

    }
    public function descativar($id)
    {

        $reglas = InstalarReglas::get();

        
        exec('sh bash/rules.sh', $rules);
        //dd($rules);
        
        $ar=fopen("local.rules", "a+") or die ("Error al crear el archivo");
  

  
    
        fwrite($ar,'alert icmp any any -> any any ( msg:"ICMP Traffic Detected"; sid:10000001; metadata:policy security-ips alert; )');
 
    }
    
}
