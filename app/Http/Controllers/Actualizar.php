<?php

namespace App\Http\Controllers;

use App\Models\Btn;
use Illuminate\Http\Request;

class Actualizar extends Controller
{
    public function __construct()
    {
        $this->middleware('auth');
    }



    public function index() { 

        $guardar = Btn::first();
        $consulta = Btn::first();

        
        
        exec('sh bash/actualizar.sh', $sistema);

       
        if ($sistema != "ERROR"){
            $guardar->sistema   = 'disabled';
            $guardar->libreria   = '';
            $guardar->update();

        }
       // dd($consulta);

        
        return view('actualizar', [
            'actualizar'    => $sistema,
            'consulta'    => $consulta,
        ]);
    }
}
