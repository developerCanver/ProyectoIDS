<?php

namespace App\Http\Controllers;

use App\Models\InstalarReglas;
use Illuminate\Http\Request;

class GestionarReglas extends Controller
{
    public function __construct()
    {
        $this->middleware('auth');
    }
    

    public function index(Request $request)
    {
    $reglas = InstalarReglas::get();

        return view('gestionarReglas',[
            'reglas' => $reglas,
        ]);
        
    }


    public function store(Request $request)
    {
   
        return view('gestionarReglas',[
            'reglas' => $reglas,
        ]);
        
    }
}
