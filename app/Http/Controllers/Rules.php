<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Redirect;
use Alert;
class Rules extends Controller
{
    public function __construct()
    {
        $this->middleware('auth');
    }
    
    public function index() {     
        return view('rules');
    }
    public function store(Request $request) { 

        exec('sh bash/rules.sh', $rules);
        //dd($rules);
        
        $ar=fopen("local.rules", "a+") or die ("Error al crear el archivo");
        
        $acccion=request('acccion');
        $protocolo=request('protocolo');
        $ipOrigen=request('ipOrigen');
        $puertoOrigen=request('puertoOrigen');
        $direccion=request('direccion');
        $ipDestino=request('ipDestino');
        $origenDestino=request('origenDestino');
        $origenDestino=request('origenDestino');

   

        $sid=0;
        if ($protocolo=='icmp') {
            $sid=1;
        }
        if ($protocolo=='tcp') {
            $sid=2;
        }
        if ($protocolo=='ip') {
            $sid=3;
        }
        if ($protocolo=='udp') {
            $sid=4;
        }
       

    
        fwrite($ar,$acccion);
        fwrite($ar,' '.$protocolo);
        fwrite($ar,' '.$ipOrigen);
        fwrite($ar,' '.$puertoOrigen);
        fwrite($ar,' '.$direccion);
        fwrite($ar,' '.$ipDestino);
        fwrite($ar,' '.$origenDestino);
        fwrite($ar,' ( msg:"ICMP Traffic Detected"; sid:1000000'.$sid.';');
        fwrite($ar,' metadata:policy security-ips alert; )');
       
        //alert icmp any any -> any any ( msg:"ICMP Traffic Detected"; sid:10000001; metadata:policy security-ips alert; )
        exec('sh bash/moverRules.sh', $rules);

        //Alert::message('this is a test message', 'info');
        return Redirect::to('rules')->with('status','La Regla se Creo correctamente');
        return \Redirect::to('/rules')->with('status','You account is now activated. Please login.');



    }

}
