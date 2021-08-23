<?php

namespace App\Http\Controllers;

use App\Models\Btn;
use Illuminate\Http\Request;

class Librerias extends Controller
{
    
        
    public function index(Request $request)
    {

        exec('sh bash/librerias.sh', $librerias);
        
        $guardar = Btn::first();
        $consulta = Btn::first();

        
      if ($librerias != "ERROR"){
            $guardar->libreria   = 'disabled';
            $guardar->paquetes   = '';
            $guardar->update();

        }

        
    return view('librerias', [
        'librerias'    => $librerias,
        'consulta'    => $consulta,
    ]);
    }
}
