<?php

namespace App\Http\Controllers;

use App\Models\Btn;
use Illuminate\Http\Request;

class Red extends Controller
{
    public function index(Request $request)
    {

        $configuracionWeb = shell_exec('sh bash/configuracionWeb.sh');
  

        $guardar = Btn::first();
        $consulta = Btn::first();

        
      if ($configuracionWeb != "ERROR"){
            $guardar->red   = 'disabled';
            $guardar->prequisitos   = '';
            $guardar->update();

        }


    return view('configurarWeb', [
        'configuracionWeb'    => $configuracionWeb,
        'consulta'    => $consulta,
    ]);
    }
}
