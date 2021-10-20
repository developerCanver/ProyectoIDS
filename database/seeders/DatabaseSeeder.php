<?php

namespace Database\Seeders;
use Illuminate\Database\Seeder;
use Illuminate\Support\Facades\DB;
use Illuminate\Support\Facades\Hash;


class DatabaseSeeder extends Seeder
{
    /**
     * Seed the application's database.
     *
     * @return void
     */
    public function run()
    {
        // \App\Models\User::factory(10)->create();

        DB::table('users')->insert([
            'name' => 'Admin',
            'email' => 'seguridadids100@gmail.com',
            'password' => Hash::make('ids12345'),
        ]);

        DB::table('btns')->insert([
                   
            'sistema'       =>  'disabled',
            'libreria'      =>  'disabled',
            'paquetes'      =>  'disabled',
            'daq'           =>  'disabled',
            'snort'         =>  'disabled',
            'red'           =>  'disabled',
            'prequisitos'   =>  'disabled',
        
        ]);

        DB::table('instalar_reglas')->insert([
                   
            'nombre'    => 'policy security-ips',
            'regla'     => 'alert icmp any any -> any any ( msg:"ICMP Traffic Detected"; sid:10000001; metadata:policy security-ips alert; )',
            'detalle'   => '',
            'estado'    => true,
        
        ]);

        DB::table('instalar_reglas')->insert([
                   
            'nombre'    => 'regla 1',
            'regla'     => 'comandoregla 1',
            'detalle'   => '',
            'estado'    => false,
        
        ]);

        DB::table('instalar_reglas')->insert([
                   
            'nombre'    => 'regla 2',
            'regla'     => 'comando de regla 2',
            'detalle'   => '',
            'estado'    => false,
        
        ]);

        DB::table('guis')->insert([
                
            'estado'    => false,
        
        ]);

        






    }
}
