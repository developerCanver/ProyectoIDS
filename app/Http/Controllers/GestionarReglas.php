<?php

namespace App\Http\Controllers;

use App\Models\InstalarReglas;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Redirect;

class GestionarReglas extends Controller
{
    public function __construct()
    {
        $this->middleware('auth');
    }
    

    public function index(Request $request)
    {
    $reglas = InstalarReglas::get();
    $opcion = 'guadar';

        return view('gestionarReglas',[
            'reglas' => $reglas,
            'opcion' => $opcion,
        ]);
        
    }


    public function store(Request $request)
    {

 
        $guardar = new InstalarReglas();

        $guardar->nombre       = $request->get('nombre');
        $guardar->regla        = $request->get('regla');
        $guardar->detalle      = $request->get('detalle');
        $guardar->estado       = 0;

        $guardar->save();

        return Redirect::to('gestionarReglas')->with('status','Se Guardo correctamente');
        
    }

    public function eliminar($id)
    {
        $eliminar = InstalarReglas::findOrfail($id);
 
        $eliminar->delete();
     
        return Redirect::to('gestionarReglas')->with('status','Se Elimino correctamente');

    }

    public function actualizar(Request $request)
    {
        $id      = $request->get('id');
 
        $guardar =  InstalarReglas::findOrfail($id);

        $guardar->nombre       = $request->get('nombre');
        $guardar->regla        = $request->get('regla');
        $guardar->detalle      = $request->get('detalle');
        $guardar->estado       = 0;

        $guardar->update();

        return Redirect::to('gestionarReglas')->with('status','Se Actualizo correctamente');
        
    }

    public function editar($id)
    {
  
        $reglas = InstalarReglas::get();
        $regla =  InstalarReglas::findOrfail($id);

        $opcion = 'editar';
    
            return view('gestionarReglas',[
                'reglas' => $reglas,
                'regla' => $regla,
                'opcion' => $opcion,
            ]);

    }
}

