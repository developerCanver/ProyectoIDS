<?php

namespace App\Http\Controllers;

use App\Models\Gui;
use Illuminate\Http\Request;

class GuiController extends Controller
{
    
    public function index(Request $request){
     
        $consulta= Gui::first();
        $estado=$consulta->estado;
        $id=$consulta->id;

        if ($estado==0) {
            
            exec('sh bash/conf_gui.sh', $validacion);

            if ($validacion != "ERROR"){   

                $guardar =  Gui::findOrfail($id);
                $guardar->estado       = 1;        
                $guardar->update();
                
            }
            
        } else {
        
            exec('sh bash/conf_gui_eje .sh', $ejecutar);
        }
        
       // dd($validacion);
        return view('resultados',[
            'estado' => $estado,
         
        ]);
      
    }
}
