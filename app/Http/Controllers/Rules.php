<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

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
        $proto=request('proto');
        $ip=request('ip');
        $mascara=request('mascara');
        $direction=request('direction');

        fwrite($ar,'# $Id: local.rules,v 1.11 2021/03/13 20:15:44 bmc Exp $'. PHP_EOL);
        fwrite($ar,'#----------------------------------'. PHP_EOL);
        fwrite($ar,'# LOCAL RULES'. PHP_EOL);
        fwrite($ar,'# Este es un ejemplopara crear el archivo RULEs para Snort'. PHP_EOL);
        fwrite($ar,$acccion);
        fwrite($ar,' '.$proto);
        fwrite($ar,$ip);
        fwrite($ar,'/');
        fwrite($ar,$mascara.' ');
        fwrite($ar,' any ');
        fwrite($ar,$direction);
        fwrite($ar,' any ');
        fwrite($ar,' any ');
        fclose($ar);
        
    }

}
