<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class Actualizar extends Controller
{
    public function __construct()
    {
        $this->middleware('auth');
    }



    public function index() { 
        
        exec('sh bash/actualizar.sh', $actualizar);

        dd($actualizar);
        return view('actualizar');
    }
}
