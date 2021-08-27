<?php

namespace App\Http\Controllers;

use App\Models\Btn;
use Illuminate\Http\Request;

class Prequisitos extends Controller
{
    public function index(Request $request)
    {

        exec('sh bash/requisitos.sh', $requisitos);

        $guardar = Btn::first();
        $consulta = Btn::first();

        
      if ($requisitos != "ERROR"){
            $guardar->prequisitos   = 'disabled';
            $guardar->update();

        }


    return view('requisitos', [
        'requisitos'    => $requisitos,
        'consulta'    => $consulta,
    ]);
    }
}

