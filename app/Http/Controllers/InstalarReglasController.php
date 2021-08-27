<?php

namespace App\Http\Controllers;

use App\Models\InstalarReglas;
use Illuminate\Http\Request;
use Session;
use Illuminate\Support\Facades\Redirect;

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

        $hoy  = date('Y-m-d');

        $actualizar = InstalarReglas::findOrfail($id);
        $actualizar->estado = 1;
        $actualizar->fecha_activada = $hoy ;
        $actualizar->update();
     

        exec('sh bash/rules.sh', $rules);
        $ar=fopen("local.rules", "a+") or die ("Error al crear el archivo");


        $reglas = InstalarReglas::where('estado', 1)
                    ->get();
               
                    foreach ($reglas as $regla) {
                    //print();
                         fwrite($ar,$regla->regla.PHP_EOL);
                    }

        exec('sh bash/moverRules.sh', $rules);

  
        return Redirect::to('instalarReglas')->with('status','Se Instala correctamente');

    }


    public function descativar($id)
    {
        exec('sh bash/rules.sh', $rules);
        $ar=fopen("local.rules", "a+") or die ("Error al crear el archivo");


        $reglas = InstalarReglas::where('estado', 1)
                    ->where('id', '!=', $id)
                    ->get();
               
                    foreach ($reglas as $regla) {
                    //print();
                         fwrite($ar,$regla->regla.PHP_EOL);
                    }

        exec('sh bash/moverRules.sh', $rules);

        $actualizar = InstalarReglas::findOrfail($id);

        $actualizar->estado = 0;
        $actualizar->fecha_activada = Null;
        $actualizar->update();
     
        return Redirect::to('instalarReglas')->with('status','Se Desistala correctamente');
        
 
    }
    
}
