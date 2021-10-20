<?php

namespace App\Http\Controllers;

use App\Models\Gui;
use Illuminate\Http\Request;

class GuiController extends Controller
{
    
    public function index(Request $request){
     
        $consulta= Gui::first();
        $estado=$consulta->estado;

        if ($estado==0) {
            
            exec('sh bash/conf_gui.sh', $validacion);

            if ($validacion == "ERROR"){   
                dd($validacion);
      
            }

        } else {
            
        }
        
      
    }
}
